
#include "Interpreter.hpp"
#include "InterpreterPrivate.hpp"

#include <cassert>
#include <iostream>

namespace script
{
   
  Interpreter::Interpreter()
    : m_d(new InterpreterPrivate())
  {
    m_d->eval = scheme_init_new();
    m_d->bindOutputPort();
  }
  
  Interpreter::Interpreter(Interpreter const& copy)
    : m_d(new InterpreterPrivate())
  {
    assert(0 && "Not allowed to create copies of an Interpreter");
  }

  Interpreter::~Interpreter()
  {
    scheme_deinit(m_d->eval);
    m_d->eval = 0;
  }
  
  bool Interpreter::isValid() const
  {
    return (m_d->eval != 0) && !m_d->hasError();
  }
  
  bool Interpreter::hasError() const
  {
    return m_d->hasError();
  }
  
  void Interpreter::loadString(std::string const& code)
  {
    assert(m_d->eval);
    
    m_d->eval->vptr->load_string(m_d->eval, code.c_str());
    
    if (m_d->checkForErrors())
      std::cout << m_d->errorMessage() << std::endl;
  }
   
}