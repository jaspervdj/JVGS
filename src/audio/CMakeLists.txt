ADD_LIBRARY( 
    audio STATIC 
    AudioManager.cpp
)

# Link to the following libraries
TARGET_LINK_LIBRARIES(
    audio
    core
    ${SDLMIXER_LIBRARY}
    ${SDL_LIBRARY}
)
