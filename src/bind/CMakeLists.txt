ADD_CUSTOM_TARGET(
     swig
     swig -lua -c++ -o ${JVGS_BINARY_DIR}/src/bind/jvgslua.cpp ${JVGS_BINARY_DIR}/src/bind/jvgslua.i
)


ADD_LIBRARY(
    bind STATIC
    jvgslua.cpp
    ScriptManager.cpp
)

TARGET_LINK_LIBRARIES(
    bind
    ${LUA_LIBRARIES}
    math
    core
    input
    game
    video
    sketch
)
