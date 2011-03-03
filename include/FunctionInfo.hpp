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

#ifndef SCHEME_CPP_FUNCTION_INFO_HPP
#define SCHEME_CPP_FUNCTION_INFO_HPP

#include "Types.hpp"
#include "TypeList.hpp"

namespace script
{

  template <typename Fun>
  struct FunctionInfo;


  template <typename R>
  struct FunctionInfo<R (*)()>
  {
    typedef R Return;
    typedef NullType Params;
  };

  template <typename R, typename P1>
  struct FunctionInfo<R (*)(P1)>
  {
    typedef R Return;
    typedef TYPELIST_1(P1) Params;
  };
  
  template <typename R, typename P1, typename P2>
  struct FunctionInfo<R (*)(P1, P2)>
  {
    typedef R Return;
    typedef TYPELIST_2(P1, P2) Params;
  };
  
  template <typename R, typename P1, typename P2, typename P3>
  struct FunctionInfo<R (*)(P1, P2, P3)>
  {
    typedef R Return;
    typedef TYPELIST_3(P1, P2, P3) Params;
  };
  
  template <typename R, typename P1, typename P2, typename P3, typename P4>
  struct FunctionInfo<R (*)(P1, P2, P3, P4)>
  {
    typedef R Return;
    typedef TYPELIST_4(P1, P2, P3, P4) Params;
  };
  
  template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
  struct FunctionInfo<R (*)(P1, P2, P3, P4, P5)>
  {
    typedef R Return;
    typedef TYPELIST_5(P1, P2, P3, P4, P5) Params;
  };
  
  template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
  struct FunctionInfo<R (*)(P1, P2, P3, P4, P5, P6)>
  {
    typedef R Return;
    typedef TYPELIST_6(P1, P2, P3, P4, P5, P6) Params;
  };
  
}

#endif

