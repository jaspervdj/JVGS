# Set up include directories.
INCLUDE_DIRECTORIES(
    ${SDL_INCLUDE_DIR}
)

ADD_LIBRARY( 
    input STATIC 
    InputConfiguration.cpp
    InputManager.cpp
)

# Link to the following libraries
TARGET_LINK_LIBRARIES(
    input
    core
)
