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

#ifndef SCHEME_CPP_SCHEME_HELPERS_HPP
#define SCHEME_CPP_SCHEME_HELPERS_HPP

#include <string>

// Forward declarations
typedef struct scheme scheme;
typedef struct cell * pointer;

namespace script { namespace sc {

  int argCount(scheme * sc, pointer arguments);

  bool boolValue(scheme * sc, pointer value);
  char charValue(pointer value);
  long intValue(pointer value);
  double realValue(pointer value);
  std::string stringValue(pointer value);

  pointer makeNil(scheme * sc);
  pointer makeBool(scheme * sc, bool value);
  pointer makeChar(scheme * sc, char value);
  pointer makeInt(scheme * sc, long value);
  pointer makeReal(scheme * sc, double value);
  pointer makeString(scheme * sc, std::string const& value);
  pointer makePair(scheme * sc, pointer a, pointer b);
  pointer makeList(scheme * sc, ...);

  pointer getArg(pointer arguments, unsigned int index);

}}

#endif

