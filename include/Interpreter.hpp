
#ifndef SCHEME_CPP_INTERPRETER_HPP_INCLUDED
#define SCHEME_CPP_INTERPRETER_HPP_INCLUDED

#include <memory>

namespace script
{
  // Forward declarations
  class InterpreterData;
   
  class Interpreter
  {
    private:
      Interpreter(Interpreter const& copy);
      Interpreter & operator = (Interpreter const& copy) { return *this; }
    
    public:
      Interpreter();
      ~Interpreter();
      
      /// Returns true if we have a valid context to execute scheme code in.
      bool isValid() const;
      
    private:
      std::auto_ptr<InterpreterData> m_data;
  };
   
}

#endif