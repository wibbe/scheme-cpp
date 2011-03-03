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

#ifndef SCHEME_CPP_INTERPRETER_HPP
#define SCHEME_CPP_INTERPRETER_HPP

#include <memory>
#include <string>

namespace script
{
  // Forward declarations
  class InterpreterPrivate;
   
  class Interpreter
  {
    private:
      Interpreter(Interpreter const& copy);
      Interpreter & operator = (Interpreter const& copy) { return *this; }
    
    public:
      Interpreter();
      ~Interpreter();

      /// Bind a C function to this interpreter
      template <typename FuncT>
      Interpreter & function(std::string const& name, FuncT func);
      
      /// Load and execute a string containing code.
      void loadString(std::string const& code);
      
      /// Returns true if we have a valid context to execute scheme code in.
      bool isValid() const;
      bool hasError() const;

      std::string getLastErrorMessage() const;
      
    private:
      std::auto_ptr<InterpreterPrivate> m_private;
  };
   
}

#include "Interpreter.inl"

#endif

