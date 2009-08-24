ADD_CUSTOM_TARGET(
     swig
     ${SWIG_EXECUTABLE} -lua -c++ -o ${JVGS_BINARY_DIR}/src/bind/jvgslua.cpp ${JVGS_BINARY_DIR}/src/bind/jvgslua.i
)

ADD_LIBRARY(
    bind STATIC
    jvgslua.cpp
    ScriptManager.cpp
)

ADD_DEPENDENCIES( bind swig )

TARGET_LINK_LIBRARIES(
    bind
    ${LUA_LIBRARIES}
    math
    core
    effect
    input
    game
    video
    audio
    sketch
)
