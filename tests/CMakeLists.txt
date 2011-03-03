
SET(SOURCE
   Main.cpp
   TestInterpreter.cpp
   TestCallbacks.cpp
)

SET(LIBRARIES
  scheme-cpp
)

INCLUDE_DIRECTORIES(
  "${CMAKE_CURRENT_SOURCE_DIR}/catch"
)

ADD_EXECUTABLE(unit_test ${SOURCE})
TARGET_LINK_LIBRARIES(unit_test ${LIBRARIES})
