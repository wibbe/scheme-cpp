
#include "catch.hpp"

#include "Interpreter.hpp"

TEST_CASE("Allocation", "Make sure we can allocate a scheme interpreter")
{
  script::Interpreter eval;
  CHECK(eval.isValid());
}

TEST_CASE("RunCode/ErrorReporting", "Run some code that should produce an error")
{
  script::Interpreter eval;
  CHECK(eval.isValid());
  
  eval.loadString("(display \"Hello World\") (print)");
  REQUIRE(eval.hasError() == false);
  REQUIRE(eval.hasError() == true);
}
