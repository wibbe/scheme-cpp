
#ifndef SCHEME_CPP_INTERPRETER_DATA_HPP_INCLUDED
#define SCHEME_CPP_INTERPRETER_DATA_HPP_INCLUDED

#include "scheme-private.h"

namespace script
{
  
  class InterpreterData
  {
    public:
      InterpreterData()
        : eval(0)
      { }
          
      scheme * eval;
  };
  
}

#endif