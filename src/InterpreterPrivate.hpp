/**
 * Copyright (c) 2011 Daniel Wiberg
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef SCHEME_CPP_INTERPRETER_PRIVATE_HPP
#define SCHEME_CPP_INTERPRETER_PRIVATE_HPP

#include "scheme.h"
#include "scheme-private.h"

#include <iostream>

namespace script
{
  
  class InterpreterPrivate
  {
    public:
      enum { OUTPUT_STRING_LENGTH = 1024 };
      
      InterpreterPrivate()
        : eval(0),
          m_error(false),
          m_lastErrorMessage("")
      { }
      
      void bindOutputPort()
      {
        memset(m_outputData, '\0', OUTPUT_STRING_LENGTH);
        scheme_set_output_port_string(eval, &m_outputData[0], &m_outputData[OUTPUT_STRING_LENGTH - 1]);
      }
      
      bool checkForErrors()
      {
        std::string::size_type pos = std::string(m_outputData).find("Error");

        if (pos != std::string::npos)
        {
          m_error = true;
          m_lastErrorMessage = std::string(m_outputData).substr(pos);
          bindOutputPort();
        }
        else
        {
          m_error = false;
          m_lastErrorMessage = "";
        }

        return m_error;
      }
      
      /// Returns true if an error has occurred.
      bool hasError() const { return m_error; }
      std::string getLastErrorMessage() const { return m_lastErrorMessage; }
      
    public:   
      scheme * eval;
      
    private:
      char m_outputData[OUTPUT_STRING_LENGTH];
      bool m_error;
      std::string m_lastErrorMessage;
  };
  
}

#endif

