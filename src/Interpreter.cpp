
#include "Interpreter.hpp"
#include "InterpreterData.hpp"

namespace script
{
   
  Interpreter::Interpreter()
    : m_data(new InterpreterData())
  {
    m_data->eval = scheme_init_new();
  }

  Interpreter::~Interpreter()
  {
    scheme_deinit(m_data->eval);
    m_data->eval = 0;
  }
   
}