
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
    return callWithArguments(name, 0);
  }

  template <typename T1>
  inline Cell Interpreter::call(std::string const& name, T1 arg1)
  {
  }

}

#endif

