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

static int callbackValue = 0;

void scriptCallback()
{
  callbackValue = 1;
}

int scriptAdd(int a, int b)
{
  return a + b;
}

void scriptString(std::string const& a)
{
}

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

TEST_CASE("RunCode/StdOutTest", "Try printing something to std out")
{
  script::Interpreter eval;
  CHECK(eval.isValid());
  
  eval.loadString("(begin (display \"Hello World\") (newline))");
  REQUIRE(eval.getStandardOut() == "Hello World\n");
}

TEST_CASE("FunctionBinding/Binding", "Try binding a C function to the interpreter")
{
  script::Interpreter eval;
  CHECK(eval.isValid());

  // Register function
  eval.function("callback", scriptCallback);
}

TEST_CASE("FunctionBinding/BindingStringFunction", "Try binding a C function that takes strings as arguments.")
{
  script::Interpreter eval;
  CHECK(eval.isValid());

  // Register function
  eval.function("callback", scriptString);
  eval.loadString("(callback \"Hello World\")");
  CHECK_FALSE(eval.hasError());
}

TEST_CASE("FunctionBinding/CallingAndReturnValue", "Try binding a C function, calling it and getting the return value.")
{
  script::Interpreter eval;
  CHECK(eval.isValid());

  // Register function
  eval.function("add", scriptAdd);
  eval.loadString("(display (add 1 2))");

  REQUIRE(eval.getStandardOut() == "3");
}

TEST_CASE("Cell/GlobalValue", "Getting a global value")
{
  script::Interpreter eval;
  CHECK(eval.isValid());

  eval.loadString("(define a 25)");
  eval.loadString("(define b 2.5)");

  script::Cell a = eval.getGlobalValue("a");
  script::Cell b = eval.getGlobalValue("b");

  CHECK_FALSE(a.isNil());
  CHECK(a.isInteger());
  CHECK(a.toInteger() == 25);
  
  CHECK_FALSE(b.isNil());
  CHECK(b.isReal());
  CHECK(b.toReal() == 2.5);
}

TEST_CASE("Cell/PairFunctions", "Test the pair car/cdr function on the Cell class.")
{
  script::Interpreter eval;
  CHECK(eval.isValid());
  
  eval.loadString("(define a '(1 2 3))");
  CHECK_FALSE(eval.hasError());
  
  script::Cell value = eval.getGlobalValue("a");
  
  CHECK_FALSE(value.isNil());
  CHECK(value.isPair());
  
  script::Cell car = value.car();
  script::Cell cdr = value.cdr();
  
  CHECK_FALSE(car.isNil());
  CHECK_FALSE(cdr.isNil());
  CHECK(car.isInteger());
  CHECK(cdr.isPair());
  
  CHECK(car.toInteger() == 1);
  CHECK(cdr.car().toInteger() == 2);
  CHECK(cdr.cdr().car().isInteger());
  CHECK(cdr.cdr().car().toInteger() == 3);
  CHECK(cdr.cdr().cdr().isNil());
}

TEST_CASE("Cell/CallFunction", "Calling a function that returns a value")
{
  script::Interpreter eval;
  CHECK(eval.isValid());

  eval.loadString("(define (my-func) 10)");

  script::Cell result = eval.call("my-func");

  CHECK_FALSE(result.isNil());
  REQUIRE(result.isInteger() == true);
  REQUIRE(result.toInteger() == 10);
}

TEST_CASE("Cell/CallFunctionWithArguments", "Calling a script function with multiple arguments")
{
  script::Interpreter eval;
  CHECK(eval.isValid());
  
  // (+ 1)
  script::Cell result = eval.call("+", 1);
  
  CHECK_FALSE(result.isNil());
  REQUIRE(result.isInteger() == true);
  REQUIRE(result.toInteger() == 1);
  
  // (+ 1 2)
  result = eval.call("+", 1, 2);
  
  CHECK_FALSE(result.isNil());
  REQUIRE(result.isInteger() == true);
  REQUIRE(result.toInteger() == 3);
  
  // (+ 1 2 3)
  result = eval.call("+", 1, 2, 3);
  
  CHECK_FALSE(result.isNil());
  REQUIRE(result.isInteger() == true);
  REQUIRE(result.toInteger() == 6);
  
  // (+ 1 2 3 4)
  result = eval.call("+", 1, 2, 3, 4);
  
  CHECK_FALSE(result.isNil());
  REQUIRE(result.isInteger() == true);
  REQUIRE(result.toInteger() == 10);
  
  // (+ 1 2 3 4 5)
  result = eval.call("+", 1, 2, 3, 4, 5);
  
  CHECK_FALSE(result.isNil());
  REQUIRE(result.isInteger() == true);
  REQUIRE(result.toInteger() == 15);
  
  // (+ 1 2 3 4 5 6)
  result = eval.call("+", 1, 2, 3, 4, 5, 6);
  
  CHECK_FALSE(result.isNil());
  REQUIRE(result.isInteger() == true);
  REQUIRE(result.toInteger() == 21);
  
  // (+ 1 2 3 4 5 6 7)
  result = eval.call("+", 1, 2, 3, 4, 5, 6, 7);
  
  CHECK_FALSE(result.isNil());
  REQUIRE(result.isInteger() == true);
  REQUIRE(result.toInteger() == 28);
  
  // (+ 1 2 3 4 5 6 7 8)
  result = eval.call("+", 1, 2, 3, 4, 5, 6, 7, 8);
  
  CHECK_FALSE(result.isNil());
  REQUIRE(result.isInteger() == true);
  REQUIRE(result.toInteger() == 36);
}

TEST_CASE("Call/CallWithStringArguments", "Calling a script function with string arguments")
{
  script::Interpreter eval;
  CHECK(eval.isValid());
  
  script::Cell result = eval.call("string-append", "Hello", " ", "World");
  
  CHECK_FALSE(result.isNil());
  REQUIRE(result.isString() == true);
  REQUIRE(result.toString() == "Hello World");
}

TEST_CASE("RunCode/LoadFromFile", "Try to load code from file")
{
  script::Interpreter eval;
  CHECK(eval.isValid());
  
  eval.loadFile("../../src/tinyscheme/init.scm");
  if (eval.hasError())
    eval.loadFile("src/tinyscheme/init.scm");
    
  INFO(eval.getLastErrorMessage());
  REQUIRE(eval.hasError() == false);
  
  script::Cell result = eval.call("gcd", 2, 4, 8, 10);
  
  CHECK_FALSE(result.isNil());
  REQUIRE(result.isInteger() == true);
  REQUIRE(result.toInteger() == 2);
}
