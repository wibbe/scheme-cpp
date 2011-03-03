
#ifndef SCHEME_CPP_SCHEME_HELPERS_HPP
#define SCHEME_CPP_SCHEME_HELPERS_HPP

typedef struct scheme scheme;
typedef struct cell * pointer;

namespace script { namespace sc {


  int argCount(scheme * sc, pointer arguments);

  bool boolValue(scheme * sc, pointer value);
  char charValue(pointer value);
  long intValue(pointer value);
  double realValue(pointer value);

  pointer makeNil(scheme * sc);
  pointer makeBool(scheme * sc, bool value);
  pointer makeChar(scheme * sc, char value);
  pointer makeInt(scheme * sc, long value);
  pointer makeReal(scheme * sc, double value);

  pointer getArgument(pointer arguments, unsigned int index);

}}

#endif

