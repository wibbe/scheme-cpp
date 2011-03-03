
#include "Scheme.hpp"
#include "scheme.h"
#include "scheme-private.h"

namespace script { namespace sc {


  int argCount(scheme * sc, pointer arguments)
  {
    if (is_pair(arguments))
      return list_length(sc, arguments);
    return 0;
  }

  bool boolValue(scheme * sc, pointer value)
  {
    return sc->T == value;
  }

  char charValue(pointer value)
  {
    return charvalue(value);
  }

  long intValue(pointer value)
  {
    return ivalue(value);
  }

  double realValue(pointer value)
  {
    return rvalue(value);
  }

  std::string stringValue(pointer value)
  {
    return std::string(string_value(value));
  }

  pointer makeNil(scheme * sc)
  {
    return sc->NIL;
  }

  pointer makeBool(scheme * sc, bool value)
  {
    return value ? sc->T : sc->F;
  }

  pointer makeChar(scheme * sc, char value)
  {
    return mk_character(sc, value);
  }

  pointer makeInt(scheme * sc, long value)
  {
    return mk_integer(sc, value);
  }

  pointer makeReal(scheme * sc, double value)
  {
    return mk_real(sc, value);
  }

  pointer makeString(scheme * sc, std::string const& value)
  {
    return mk_string(sc, value.c_str());
  }

  pointer getArg(pointer arguments, unsigned int index)
  {
    while (index != 0)
    {
      arguments = pair_cdr(arguments);
      --index;
    }

    return is_pair(arguments) ? pair_car(arguments) : arguments;
  }

}}

