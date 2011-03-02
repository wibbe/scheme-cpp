
#include "catch.hpp"

#include "Interpreter.hpp"

TEST_CASE("Allocation", "Make sure we can allocate a scheme interpreter")
{
  script::Interpreter eval;
  REQUIRE(eval.isValid() == true);
}
