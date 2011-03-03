
#ifndef SCHEME_CPP_FUNCTION_WRAPPER_HPP
#define SCHEME_CPP_FUNCTION_WRAPPER_HPP

#include "FunctionInfo.hpp"
#include "Scheme.hpp"

namespace script
{

  class BasicFunction
  {
    public:
      virtual pointer call(scheme * sc, pointer arguments) = 0;
  };

  template <int ArgCount, typename FuncT, typename ReturnT, typename ParamT>
  class Function : public BasicFunction { };

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
        return scNil(sc);
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
        m_function();
      }

    private:
      FuncT m_function;
  };

  template <typename FuncT, typename ReturnT, typename P1>
  class Function<1, FuncT, ReturnT, TYPELIST_1(P1)> : public BasicFunction
  {
    public:
      Function(FuncT function)
        : m_function(function)
      { }

      pointer call(scheme * sc, pointer arguments)
      {
      }

    private:
      FuncT m_function;
  };


  class FunctionWrapper
  {
    public:
      template <typename FuncT>
      FunctionWrapper(FuncT function)
        : m_function(static_cast<BasicFunction *>(new Function<TL::Length<typename FunctionInfo<FuncT>::Params>::Value, FuncT, typename FunctionInfo<FuncT>::Return, typename FunctionInfo<FuncT>::Params>(function)))
      { }

      virtual ~FunctionWrapper()
      {
        delete m_function;
      }

      pointer operator () (scheme * sc, pointer arguments)
      {
        return m_function->call(sc, arguments);
      }

    private:
      BasicFunction * m_function;
  };

}

#endif

