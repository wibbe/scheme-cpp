
#include "Cell.hpp"
#include "scheme.h"
#include "scheme-private.h"

namespace script
{

  Cell::Cell(scheme * sc, pointer value)
    : m_type(FROM_SCHEME),
      m_scheme(sc),
      m_value(value)
  {
  }

  Cell::Cell()
    : m_type(NONE),
      m_scheme(0),
      m_value(0)
  {
  }

  Cell::Cell(Cell const& copy)
    : m_type(copy.m_type),
      m_scheme(copy.m_scheme),
      m_value(copy.m_value),
      m_stored(copy.m_stored),
      m_storedString(copy.m_storedString)
  {
  }

  Cell::Cell(long value)
    : m_type(INTEGER),
      m_scheme(0),
      m_value(0),
      m_storedString("")
  {
    m_stored.integer = value;
  }

  Cell::Cell(double value)
    : m_type(REAL),
      m_scheme(0),
      m_value(0),
      m_storedString("")
  {
    m_stored.real = value;
  }

  Cell::Cell(bool value)
    : m_type(BOOLEAN),
      m_scheme(0),
      m_value(0),
      m_storedString("")
  {
    m_stored.boolean = value;
  }

  Cell::Cell(std::string const& value)
    : m_type(STRING),
      m_scheme(0),
      m_value(0),
      m_storedString(value)
  {
  }

  Cell(Cell const& car, Cell const& cdr)
    : m_type(PAIR),
      m_scheme(0),
      m_value(0),
      m_storedCar(car),
      m_storedCdr(cdr)
  {
  }

  bool Cell::isBoolean() const
  {
    return m_value == m_scheme->T || m_value == m_scheme->F || m_type == BOOLEAN;
  }

  bool Cell::isInteger() const
  {
    return is_integer(m_value) || m_type == INTEGER;
  }

  bool Cell::isReal() const
  {
    return is_real(m_value) || m_type == REAL;
  }

  bool Cell::isString() const
  {
    return is_string(m_value) || m_type == STRING;
  }

  bool Cell::isSymbol() const
  {
    return is_symbol(m_value);
  }

  bool Cell::isNil() const
  {
    return m_type == NONE || m_value == m_scheme->NIL;
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

  pointer Cell::toScheme(scheme * sc) const
  {
    switch (m_type)
    {
      case NONE:
        return sc->NIL;
      case FROM_SCHEME:
        return m_value;
      case BOOLEAN:
        return m_stored.boolean ? sc->T : sc->F;
      case INTEGER:
        return mk_integer(sc, m_stored.integer);
      case REAL:
        return mk_real(sc, m_stored.real);
      case STRING:
        return mk_string(sc, m_storedString.c_str());
      case PAIR:
        return cons(m_storedCar.toScheme(sc), m_storedCdr.toScheme(sc));
    }

    return 0;
  }

}

