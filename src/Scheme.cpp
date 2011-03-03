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
 
#include "Scheme.hpp"
#include "scheme.h"
#include "scheme-private.h"

#include <cstdarg>
#include <stack>

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
  
  pointer makePair(scheme * sc, pointer a, pointer b)
  {
    return cons(sc, a, b);
  }
  
  pointer makeList(scheme * sc, ...)
  {
    va_list args;
    
    std::stack<pointer> elements;
    
    // First we build the stack
    va_start(args, sc);
    
    do
    {
      elements.push(va_arg(args, pointer));
    }
    while (elements.top() != 0);
    
    va_end(args);
    
    // Pop the first 0
    elements.pop();

    // Build the scheme list
    pointer result = sc->NIL;
  
    for (;!elements.empty(); elements.pop())
    {
      pointer element = elements.top();
      result = cons(sc, element, result);
    }
    
    return result;
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

