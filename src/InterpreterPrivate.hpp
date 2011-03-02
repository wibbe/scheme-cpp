
#ifndef SCHEME_CPP_INTERPRETER_PRIVATE_HPP_INCLUDED
#define SCHEME_CPP_INTERPRETER_PRIVATE_HPP_INCLUDED

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
        m_error = std::string(m_outputData, 5) == "Error";
        
        std::cout << "Out: " <<   std::string(m_outputData) << std::endl;
        
        if (m_error)
        {
          m_lastErrorMessage = std::string(m_outputData);
          std::cout << m_lastErrorMessage;
          std::cerr << m_lastErrorMessage;
          bindOutputPort();
        }
        else
        {
          m_lastErrorMessage = "";
        }
        
        return m_error;
      }
      
      /// Returns true if an error has occurred.
      bool hasError() const { return m_error; }
      std::string errorMessage() const { return m_lastErrorMessage; }
      
    public:   
      scheme * eval;
      
    private:
      char m_outputData[OUTPUT_STRING_LENGTH];
      bool m_error;
      std::string m_lastErrorMessage;
  };
  
}

#endif