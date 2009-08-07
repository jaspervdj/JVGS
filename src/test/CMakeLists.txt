# Set up include directories.
INCLUDE_DIRECTORIES(
    ${SDL_INCLUDE_DIR}
)

ADD_EXECUTABLE(
    pathTest pathTest.cpp
)

TARGET_LINK_LIBRARIES(
    pathTest math core sketch
)

ADD_EXECUTABLE(
    mathTest mathTest.cpp
)

TARGET_LINK_LIBRARIES(
    mathTest math core
)

ADD_EXECUTABLE(
    levelTest levelTest.cpp
)

TARGET_LINK_LIBRARIES(
    levelTest sketch math game input bind
)

ADD_EXECUTABLE(
    performanceTest performanceTest.cpp
)

TARGET_LINK_LIBRARIES(
    performanceTest sketch
)

ADD_EXECUTABLE(
    sketchTest sketchTest.cpp
)

TARGET_LINK_LIBRARIES(
    sketchTest sketch game input
)

ADD_EXECUTABLE(
    matrixTest matrixTest.cpp
)

TARGET_LINK_LIBRARIES(
    matrixTest math core
)
