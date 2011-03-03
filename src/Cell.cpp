
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
    return is_integer(m_value);
  }

  bool Cell::isReal() const
  {
    return is_real(m_value);
  }

  bool Cell::isString() const
  {
    return is_string(m_value);
  }

  bool Cell::isSymbol() const
  {
    return is_symbol(m_value);
  }

  bool Cell::isNil() const
  {
    return m_value == m_scheme->NIL;
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
    return m_value == m_scheme->NIL;
  }

  std::string Cell::toString() const
  {
    if (isSymbol())
      return symname(m_value);
    return string_value(m_value);
  }

}

