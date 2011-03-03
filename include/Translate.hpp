/**
 * Copyright (c) 2010 Daniel Wiberg
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

#ifndef SCHEME_CPP_TRANSLATE_HPP
#define SCHEME_CPP_TRANSLATE_HPP

#include "Scheme.hpp"

namespace script 
{

  template <typename T>
  struct Translate;

  template <>
  struct Translate<bool>
  {
    static bool fromScheme(scheme * sc, pointer value)
    {
      return sc::boolValue(sc, value);
    }

    static pointer toScheme(scheme * sc, bool value)
    {
      return sc::makeBool(sc, value);
    }
  };

  template <>
  struct Translate<char>
  {
    static char fromScheme(scheme * sc, pointer value)
    {
      return sc::charValue(value);
    }

    static pointer toScheme(scheme * sc, char value)
    {
      return sc::makeChar(sc, value);
    }
  };

  template <>
  struct Translate<unsigned char>
  {
    static unsigned char fromScheme(scheme * sc, pointer value)
    {
      return sc::intValue(value);
    }

    static pointer toScheme(scheme * sc, unsigned char value)
    {
      return sc::makeInt(sc, value);
    }
  };

  template <>
  struct Translate<short>
  {
    static short fromScheme(scheme * sc, pointer value)
    {
      return sc::intValue(value);
    }

    static pointer toScheme(scheme * sc, short value)
    {
      return sc::makeInt(sc, value);
    }
  };

  template <>
  struct Translate<unsigned short>
  {
    static unsigned short fromScheme(scheme * sc, pointer value)
    {
      return sc::intValue(value);
    }

    static pointer toScheme(scheme * sc, unsigned short value)
    {
      return sc::makeInt(sc, value);
    }
  };

  template <>
  struct Translate<int>
  {
    static int fromScheme(scheme * sc, pointer value)
    {
      return sc::intValue(value);
    }

    static pointer toScheme(scheme * sc, int value)
    {
      return sc::makeInt(sc, value);
    }
  };

  template <>
  struct Translate<unsigned int>
  {
    static unsigned int fromScheme(scheme * sc, pointer value)
    {
      return sc::intValue(value);
    }

    static pointer toScheme(scheme * sc, unsigned int value)
    {
      return sc::makeInt(sc, value);
    }
  };

  template <>
  struct Translate<long>
  {
    static long fromScheme(scheme * sc, pointer value)
    {
      return sc::intValue(value);
    }

    static pointer toScheme(scheme * sc, long value)
    {
      return sc::makeInt(sc, value);
    }
  };

  template <>
  struct Translate<unsigned long>
  {
    static unsigned long fromScheme(scheme * sc, pointer value)
    {
      return sc::intValue(value);
    }

    static pointer toScheme(scheme * sc, unsigned long value)
    {
      return sc::makeInt(sc, value);
    }
  };

  template <>
  struct Translate<float>
  {
    static float fromScheme(scheme * sc, pointer value)
    {
      return sc::realValue(value);
    }

    static pointer toScheme(scheme * sc, float value)
    {
      return sc::makeReal(sc, value);
    }
  };

  template <>
  struct Translate<double>
  {
    static double fromScheme(scheme * sc, pointer value)
    {
      return sc::realValue(value);
    }

    static pointer toScheme(scheme * sc, double value)
    {
      return sc::makeReal(sc, value);
    }
  };

  template <>
  struct Translate<std::string>
  {
    static std::string fromScheme(scheme * sc, pointer value)
    {
      return sc::stringValue(value);
    }

    static pointer toScheme(scheme * sc, std::string const& value)
    {
      return sc::makeString(sc, value);
    }
  };

  template <>
  struct Translate<std::string const&>
  {
    static std::string fromScheme(scheme * sc, pointer value)
    {
      return sc::stringValue(value);
    }

    static pointer toScheme(scheme * sc, std::string const& value)
    {
      return sc::makeString(sc, value);
    }
  };

}

#endif

