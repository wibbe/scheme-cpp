
#ifndef SCHEME_CPP_CELL_HPP
#define SCHEME_CPP_CELL_HPP

#include "Scheme.hpp"

namespace script
{
  // Forward declarations
  class Interpreter;
  class Cell;

  class Cell
  { 
      enum TYPE
      {
        NONE,
        FROM_SCHEME,
        BOOLEAN,
        INTEGER,
        REAL,
        STRING,
        PAIR
      };

    protected:
      Cell(scheme * sc, pointer value);

    public:
      Cell();
      Cell(Cell const& copy);

      Cell(long value);
      Cell(double value);
      Cell(bool value);
      Cell(std::string const& value);
      Cell(Cell const& car, Cell const& cdr);

      bool isBoolean() const;
      bool isInteger() const;
      bool isReal() const;
      bool isString() const;
      bool isSymbol() const;
      bool isNil() const;

      long toInteger() const;
      double toReal() const;
      bool toBoolean() const;
      std::string toString() const;

      pointer toScheme(scheme * sc) const;

    private:
      TYPE m_type;
      scheme * m_scheme;
      pointer m_value;

      union
      {
        long integer;
        double real;
        bool boolean;
      } m_stored;

      std::string m_storedString;

      Cell m_storedCar;
      Cell m_storedCdr;

      friend class Interpreter;
  };

}

#endif

