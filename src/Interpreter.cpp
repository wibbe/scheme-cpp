
#include "Interpreter.hpp"
#include "InterpreterData.hpp"

#include <cassert>

namespace script
{
   
  Interpreter::Interpreter()
    : m_data(new InterpreterData())
  {
    m_data->eval = scheme_init_new();
  }
  
  Interpreter::Interpreter(Interpreter const& copy)
    : m_data(new InterpreterData())
  {
    assert(0 && "Not allowed to create copies of an Interpreter");
  }

  Interpreter::~Interpreter()
  {
    scheme_deinit(m_data->eval);
    m_data->eval = 0;
  }
  
  bool Interpreter::isValid() const
  {
    return m_data->eval != 0;
  }
   
}