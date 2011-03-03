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
  
  eval.loadString("(my-own-print 'Hello World')");

  INFO("Make sure we got an error, and that it was the correct error");
  REQUIRE(eval.hasError() == true);
  CHECK(eval.getLastErrorMessage().find("unbound variable: my-own-print") != std::string::npos);
}

