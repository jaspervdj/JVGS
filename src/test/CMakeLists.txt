# Set up include directories.
INCLUDE_DIRECTORIES(
    ${SDL_INCLUDE_DIR}
)

ADD_EXECUTABLE(
    collisionTest collisionTest.cpp
)

TARGET_LINK_LIBRARIES(
    collisionTest sketch math
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
    sketchTest sketch
)

ADD_EXECUTABLE(
    matrixTest matrixTest.cpp
)

TARGET_LINK_LIBRARIES(
    matrixTest math core
)
