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
 
#include "Cell.hpp"
#include "scheme.h"
#include "scheme-private.h"

namespace script
{

  Cell::Cell(scheme * sc, pointer value)
    : m_scheme(sc),
      m_value(value)
  {
  }

  Cell::Cell()
    : m_scheme(0),
      m_value(0)
  {
  }

  Cell::Cell(Cell const& copy)
    : m_scheme(copy.m_scheme),
      m_value(copy.m_value)
  {
  }

  bool Cell::isBoolean() const
  {
    return m_value == m_scheme->T || m_value == m_scheme->F;
  }

  bool Cell::isInteger() const
  {
    return m_value && is_integer(m_value);
  }

  bool Cell::isReal() const
  {
    return m_value && is_real(m_value);
  }

  bool Cell::isString() const
  {
    return m_value && is_string(m_value);
  }

  bool Cell::isSymbol() const
  {
    return m_value && is_symbol(m_value);
  }

  bool Cell::isNil() const
  {
    return m_value == m_scheme->NIL;
  }
  
  bool Cell::isPair() const
  {
    return m_value && is_pair(m_value);
  }

  long Cell::toInteger() const
  {
    return ivalue(m_value);
  }

  double Cell::toReal() const
  {
    return rvalue(m_value);
  }

  bool Cell::toBoolean() const
  {
    return m_value == m_scheme->T;
  }

  std::string Cell::toString() const
  {
    if (isSymbol())
      return symname(m_value);
      
    return string_value(m_value);
  }

}

