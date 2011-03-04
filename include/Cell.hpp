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
 
#ifndef SCHEME_CPP_CELL_HPP
#define SCHEME_CPP_CELL_HPP

#include "Scheme.hpp"

namespace script
{
  // Forward declarations
  class Interpreter;

  class Cell
  {
    protected:
      Cell(scheme * sc, pointer value);

    public:
      Cell();
      Cell(Cell const& copy);

      bool isBoolean() const;
      bool isInteger() const;
      bool isReal() const;
      bool isString() const;
      bool isSymbol() const;
      bool isNil() const;
      bool isPair() const;

      long toInteger() const;
      double toReal() const;
      bool toBoolean() const;
      std::string toString() const;

      Cell car() const;
      Cell cdr() const;

    private:
      scheme * m_scheme;
      pointer m_value;

      friend class Interpreter;
  };

}

#endif


