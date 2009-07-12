ADD_CUSTOM_TARGET(
     swig
     swig -lua -c++ -o ${JVGS_BINARY_DIR}/src/bind/jvgs.cpp ${JVGS_BINARY_DIR}/src/bind/jvgs.i
)


ADD_LIBRARY(
    jvgs SHARED
    jvgs.cpp
)

SET_TARGET_PROPERTIES(
    jvgs PROPERTIES PREFIX ""
)

TARGET_LINK_LIBRARIES(
    jvgs
    ${LUA_LIBRARIES}
    math
    core
    input
    game
    video
    sketch
)
