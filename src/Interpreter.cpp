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

#include "Interpreter.hpp"
#include "InterpreterPrivate.hpp"

#include <cassert>
#include <iostream>

namespace script
{
   
  Interpreter::Interpreter()
    : m_private(new InterpreterPrivate())
  {
    m_private->eval = scheme_init_new();
    m_private->bindOutputPort();
  }
  
  Interpreter::Interpreter(Interpreter const& copy)
    : m_private(new InterpreterPrivate())
  {
    assert(0 && "Not allowed to create copies of an Interpreter");
  }

  Interpreter::~Interpreter()
  {
    scheme_deinit(m_private->eval);
    m_private->eval = 0;

    // Delete all the wrappers
    for (std::list<FunctionWrapper*>::iterator it = m_private->wrappers.begin(), end = m_private->wrappers.end(); it != end; ++it)
      delete *it;

    m_private->wrappers.clear();
  }
  
  bool Interpreter::isValid() const
  {
    return (m_private->eval != 0) && !m_private->hasError();
  }
  
  bool Interpreter::hasError() const
  {
    return m_private->hasError();
  }

  std::string Interpreter::getLastErrorMessage() const
  {
    return m_private->getLastErrorMessage();
  }

  std::string Interpreter::getStandardOut()
  {
    return m_private->getStdOut();
  }

  void Interpreter::registerFunction(std::string const& name, FunctionWrapper * wrapper)
  {
    assert(m_private->eval);

    // Store the wrapper so we can delete it later on.
    m_private->wrappers.push_back(wrapper);

    // Bind the function to scheme
    scheme_define(m_private->eval, m_private->eval->global_env, mk_symbol(m_private->eval, name.c_str()), mk_foreign_func(m_private->eval, (foreign_func)(wrapper)));
  }
  
  void Interpreter::loadString(std::string const& code)
  {
    assert(m_private->eval);

    m_private->bindOutputPort();
    m_private->eval->vptr->load_string(m_private->eval, code.c_str());
    
    if (m_private->checkForErrors())
      std::cerr << m_private->getLastErrorMessage() << std::endl;
  }
   
}

