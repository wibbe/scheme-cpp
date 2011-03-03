
#ifndef SCHEME_CPP_INTERPRETER_INLINE_HPP
#define SCHEME_CPP_INTERPRETER_INLINE_HPP

namespace script
{

  template <typename FuncT>
  Interpreter & Interpreter::function(std::string const& name, FuncT func)
  {
    return *this;
  }

}

#endif

