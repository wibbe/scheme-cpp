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

#ifndef SCHEME_CPP_FUNCTION_WRAPPER_HPP
#define SCHEME_CPP_FUNCTION_WRAPPER_HPP

#include "FunctionInfo.hpp"
#include "Scheme.hpp"
#include "Translate.hpp"

namespace script
{

  class BasicFunction
  {
    public:
      virtual pointer call(scheme * sc, pointer arguments) = 0;
  };


  template <int ArgCount, typename FuncT, typename ReturnT, typename ParamT>
  class Function : public BasicFunction { };

  // - Function with no arguments

  template <typename FuncT>
  class Function<0, FuncT, void, NullType> : public BasicFunction
  {
    public:

      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer arguments)
      {
        m_function();
        return sc::makeNil(sc);
      }

    private:
      FuncT m_function;
  };

  template <typename FuncT, typename ReturnT>
  class Function<0, FuncT, ReturnT, NullType> : public BasicFunction
  {
    public:

      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer arguments)
      {
        return Translate<ReturnT>::toScheme(sc, m_function());
      }

    private:
      FuncT m_function;
  };

  // -- Function with 1 argument

  template <typename FuncT, typename ReturnT, typename P1>
  class Function<1, FuncT, ReturnT, TYPELIST_1(P1)> : public BasicFunction
  {
    public:
      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer args)
      {
        return Translate<ReturnT>::toScheme(sc, m_function(Translate<P1>::fromScheme(sc, sc::getArg(args, 0))));
      }

    private:
      FuncT m_function;
  };

  template <typename FuncT, typename P1>
  class Function<1, FuncT, void, TYPELIST_1(P1)> : public BasicFunction
  {
    public:
      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer args)
      {
        m_function(Translate<P1>::toScheme(sc, sc::getArg(args, 0)));
        return sc::makeNil(sc);
      }

    private:
      FuncT m_function;
  };

  // -- Function with 2 arguments

  template <typename FuncT, typename ReturnT, typename P1, typename P2>
  class Function<2, FuncT, ReturnT, TYPELIST_2(P1, P2)> : public BasicFunction
  {
    public:
      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer args)
      {
        return Translate<ReturnT>::toScheme(sc, m_function(Translate<P1>::fromScheme(sc, sc::getArg(args, 0)), 
                                                           Translate<P2>::fromScheme(sc, sc::getArg(args, 1))));
      }

    private:
      FuncT m_function;
  };

  template <typename FuncT, typename P1, typename P2>
  class Function<2, FuncT, void, TYPELIST_2(P1, P2)> : public BasicFunction
  {
    public:
      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer args)
      {
        m_function(Translate<P1>::fromScheme(sc, sc::getArg(args, 0)), 
                   Translate<P2>::fromScheme(sc, sc::getArg(args, 1)));
        return sc::makeNil(sc);
      }

    private:
      FuncT m_function;
  };

  // -- Function with 3 arguments

  template <typename FuncT, typename ReturnT, typename P1, typename P2, typename P3>
  class Function<3, FuncT, ReturnT, TYPELIST_3(P1, P2, P3)> : public BasicFunction
  {
    public:
      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer args)
      {
        return Translate<ReturnT>::toScheme(sc, m_function(Translate<P1>::fromScheme(sc, sc::getArg(args, 0)), 
                                                           Translate<P2>::fromScheme(sc, sc::getArg(args, 1)), 
                                                           Translate<P3>::fromScheme(sc, sc::getArg(args, 2))));
      }

    private:
      FuncT m_function;
  };

  template <typename FuncT, typename P1, typename P2, typename P3>
  class Function<3, FuncT, void, TYPELIST_3(P1, P2, P3)> : public BasicFunction
  {
    public:
      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer args)
      {
        m_function(Translate<P1>::fromScheme(sc, sc::getArg(args, 0)), 
                   Translate<P2>::fromScheme(sc, sc::getArg(args, 1)),
                   Translate<P3>::fromScheme(sc, sc::getArg(args, 2)));
        return sc::makeNil(sc);
      }

    private:
      FuncT m_function;
  };

  // -- Function with 4 arguments

  template <typename FuncT, typename ReturnT, typename P1, typename P2, typename P3, typename P4>
  class Function<4, FuncT, ReturnT, TYPELIST_4(P1, P2, P3, P4)> : public BasicFunction
  {
    public:
      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer args)
      {
        return Translate<ReturnT>::toScheme(sc, m_function(Translate<P1>::fromScheme(sc, sc::getArg(args, 0)), 
                                                           Translate<P2>::fromScheme(sc, sc::getArg(args, 1)), 
                                                           Translate<P3>::fromScheme(sc, sc::getArg(args, 2)), 
                                                           Translate<P4>::fromScheme(sc, sc::getArg(args, 3))));
      }

    private:
      FuncT m_function;
  };

  template <typename FuncT, typename P1, typename P2, typename P3, typename P4>
  class Function<4, FuncT, void, TYPELIST_4(P1, P2, P3, P4)> : public BasicFunction
  {
    public:
      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer args)
      {
        m_function(Translate<P1>::toScheme(sc, sc::getArg(args, 0)), 
                   Translate<P2>::toScheme(sc, sc::getArg(args, 1)), 
                   Translate<P3>::toScheme(sc, sc::getArg(args, 2)), 
                   Translate<P4>::toScheme(sc, sc::getArg(args, 3)));
        return sc::makeNil(sc);
      }

    private:
      FuncT m_function;
  };

  // -- Function with 5 arguments

  template <typename FuncT, typename ReturnT, typename P1, typename P2, typename P3, typename P4, typename P5>
  class Function<5, FuncT, ReturnT, TYPELIST_5(P1, P2, P3, P4, P5)> : public BasicFunction
  {
    public:
      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer args)
      {
        return Translate<ReturnT>::toScheme(sc, m_function(Translate<P1>::fromScheme(sc, sc::getArg(args, 0)), 
                                                           Translate<P2>::fromScheme(sc, sc::getArg(args, 1)), 
                                                           Translate<P3>::fromScheme(sc, sc::getArg(args, 2)), 
                                                           Translate<P4>::fromScheme(sc, sc::getArg(args, 3)),
                                                           Translate<P5>::fromScheme(sc, sc::getArg(args, 4))));
      }

    private:
      FuncT m_function;
  };

  template <typename FuncT, typename P1, typename P2, typename P3, typename P4, typename P5>
  class Function<5, FuncT, void, TYPELIST_5(P1, P2, P3, P4, P5)> : public BasicFunction
  {
    public:
      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer args)
      {
        m_function(Translate<P1>::toScheme(sc, sc::getArg(args, 0)), 
                   Translate<P2>::toScheme(sc, sc::getArg(args, 1)), 
                   Translate<P3>::toScheme(sc, sc::getArg(args, 2)), 
                   Translate<P4>::toScheme(sc, sc::getArg(args, 3)),
                   Translate<P5>::toScheme(sc, sc::getArg(args, 4)));
        return sc::makeNil(sc);
      }

    private:
      FuncT m_function;
  };
}

#endif

