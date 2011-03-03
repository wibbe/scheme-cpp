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

#ifndef SCHEME_CPP_INTERPRETER_INLINE_HPP
#define SCHEME_CPP_INTERPRETER_INLINE_HPP

namespace script
{

  template <typename FuncT>
  Interpreter & Interpreter::function(std::string const& name, FuncT func)
  {
    registerFunction(name, static_cast<BasicFunction *>(new Function<TL::Length<typename FunctionInfo<FuncT>::Params>::Value, FuncT, typename FunctionInfo<FuncT>::Return, typename FunctionInfo<FuncT>::Params>(func)));
    return *this;
  }

  Cell Interpreter::call(std::string const& name)
  {
    return callWithArguments(name, sc::makeNil(getScheme()));
  }

  template <typename T1>
  inline Cell Interpreter::call(std::string const& name, T1 arg1)
  {
    scheme * sc = getScheme();
    
    return callWithArguments(name, sc::makeList(sc, Translate<T1>::toScheme(sc, arg1), 0));
  }


  template <typename T1, typename T2>
  inline Cell Interpreter::call(std::string const& name, T1 arg1, T2 arg2)
  {
    scheme * sc = getScheme();
    return callWithArguments(name, sc::makeList(sc, Translate<T1>::toScheme(sc, arg1), 
                                                    Translate<T2>::toScheme(sc, arg2),
                                                    0));
  }
 
  template <typename T1, typename T2, typename T3>
  inline Cell Interpreter::call(std::string const& name, T1 arg1, T2 arg2, T3 arg3)
  {
    scheme * sc = getScheme();
    return callWithArguments(name, sc::makeList(sc, Translate<T1>::toScheme(sc, arg1), 
                                                    Translate<T2>::toScheme(sc, arg2),
                                                    Translate<T3>::toScheme(sc, arg3),
                                                    0));
  }
  
  template <typename T1, typename T2, typename T3, typename T4>
  inline Cell Interpreter::call(std::string const& name, T1 arg1, T2 arg2, T3 arg3, T4 arg4)
  {
    scheme * sc = getScheme();
    return callWithArguments(name, sc::makeList(sc, Translate<T1>::toScheme(sc, arg1), 
                                                    Translate<T2>::toScheme(sc, arg2),
                                                    Translate<T3>::toScheme(sc, arg3),
                                                    Translate<T4>::toScheme(sc, arg4),
                                                    0));
  }
  
  template <typename T1, typename T2, typename T3, typename T4, typename T5>
  inline Cell Interpreter::call(std::string const& name, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5)     
  {
    scheme * sc = getScheme();
    return callWithArguments(name, sc::makeList(sc, Translate<T1>::toScheme(sc, arg1), 
                                                    Translate<T2>::toScheme(sc, arg2),
                                                    Translate<T3>::toScheme(sc, arg3),
                                                    Translate<T4>::toScheme(sc, arg4),
                                                    Translate<T5>::toScheme(sc, arg5),
                                                    0));
  }
  
  template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
  inline Cell Interpreter::call(std::string const& name, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6)
  {
    scheme * sc = getScheme();
    return callWithArguments(name, sc::makeList(sc, Translate<T1>::toScheme(sc, arg1), 
                                                    Translate<T2>::toScheme(sc, arg2),
                                                    Translate<T3>::toScheme(sc, arg3),
                                                    Translate<T4>::toScheme(sc, arg4),
                                                    Translate<T5>::toScheme(sc, arg5),
                                                    Translate<T6>::toScheme(sc, arg6),
                                                    0));
  }

}

#endif

