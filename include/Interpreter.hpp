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

#include "Cell.hpp"
#include "FunctionWrapper.hpp"

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

      /// Bind a C function to this interpreter. After this, the function can be called from scheme using the supplied name.
      template <typename FuncT>
      Interpreter & function(std::string const& name, FuncT func);
      
      /// Load and execute a string containing code.
      void loadString(std::string const& code);
      
      /// Load and execute a file.
      /// \return True if files was loaded successfully.
      bool loadFile(std::string const& filename);

      /// Returns a globally defined script object/value.
      Cell getGlobalValue(std::string const& name);

      /// Call a script function, and pass it arguments
      inline Cell call(std::string const& name);

      template <typename T1>
      inline Cell call(std::string const& name, T1 arg1);
      
      template <typename T1, typename T2>
      inline Cell call(std::string const& name, T1 arg1, T2 arg2);
      
      template <typename T1, typename T2, typename T3>
      inline Cell call(std::string const& name, T1 arg1, T2 arg2, T3 arg3);
      
      template <typename T1, typename T2, typename T3, typename T4>
      inline Cell call(std::string const& name, T1 arg1, T2 arg2, T3 arg3, T4 arg4);
      
      template <typename T1, typename T2, typename T3, typename T4, typename T5>
      inline Cell call(std::string const& name, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5);      
      
      template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
      inline Cell call(std::string const& name, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6);

      template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
      inline Cell call(std::string const& name, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7);

      template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
      inline Cell call(std::string const& name, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8);
      
      /// Returns true if we have a valid context to execute scheme code in.
      bool isValid() const;

      /// Returns true if an error has occurred during script execution.
      bool hasError() const;

      /// Returns the last error message that occurred.
      std::string getLastErrorMessage() const;

      /// Returns the last output written to standard out.
      std::string getStandardOut();

    private:
      void registerFunction(std::string const& name, BasicFunction * function);
      Cell callWithArguments(std::string const& name, pointer args);
      
      scheme * getScheme() const;
      
    private:
      std::auto_ptr<InterpreterPrivate> m_private;
  };
   
}

#include "Interpreter.inl"

#endif

