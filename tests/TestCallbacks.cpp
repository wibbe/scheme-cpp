
#include "catch.hpp"


struct CallbackTest
{
  int operator () (int value)
  {
    return value + 1;
  }
};

typedef int (*CallbackPtr)(int);

TEST_CASE("TestCallbacks", "Testing various ways to implements C callbacks")
{
  //CallbackPtr callback;
  //CallbackTest * test = new CallbackTest;

  //callback = (CallbackPtr)(*test);

  
  //REQUIRE(callback(1) == 2);
}

