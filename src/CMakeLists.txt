
SET(SOURCE
   Interpreter.cpp
)

SET(LIBRARIES
)

ADD_LIBRARY(scheme-cpp ${SOURCE})
TARGET_LINK_LIBRARIES(scheme-cpp ${LIBRARIES})

