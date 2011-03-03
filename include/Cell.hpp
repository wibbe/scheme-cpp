
#ifndef SCHEME_CPP_CELL_HPP
#define SCHEME_CPP_CELL_HPP

#include "Scheme.hpp"

namespace script
{
  // Forward declarations
  class Interpreter;

  class Cell
  {
    protected:
      Cell(scheme * sc, pointer value);

    public:
      Cell();
      Cell(Cell const& copy);

      bool isBoolean() const;
      bool isInteger() const;
      bool isReal() const;
      bool isString() const;
      bool isSymbol() const;
      bool isNil() const;
      bool isPair() const;

      long toInteger() const;
      double toReal() const;
      bool toBoolean() const;
      std::string toString() const;

    private:
      scheme * m_scheme;
      pointer m_value;

      friend class Interpreter;
  };

}

#endif

