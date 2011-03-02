
#ifndef SCHEME_CPP_INTERPRETER_HPP_INCLUDED
#define SCHEME_CPP_INTERPRETER_HPP_INCLUDED

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
      
      /// Load and execute a string containing code.
      void loadString(std::string const& code);
      
      /// Returns true if we have a valid context to execute scheme code in.
      bool isValid() const;
      bool hasError() const;
      
    private:
      std::auto_ptr<InterpreterPrivate> m_d;
  };
   
}

#endif