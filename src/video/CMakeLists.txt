# Set up include directories.
INCLUDE_DIRECTORIES(
    ${SDL_INCLUDE_DIR}
    ${PNG_INLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${FREETYPE_INCLUDE_DIRS}
)

ADD_LIBRARY( 
    video SHARED 
    Color.cpp
    ListManager.cpp
    Renderer.cpp
    VideoManager.cpp
)

# Link to the following libraries
TARGET_LINK_LIBRARIES(
    video
    math
    ${SDL_LIBRARY}
    ${PNG_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${FREETYPE_LIBRARIES}
)
