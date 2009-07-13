INCLUDE_DIRECTORIES(
    ${SDL_INCLUDE_DIR}
)

ADD_LIBRARY( 
    game SHARED 
    Affector.cpp
    CollisionResponseAffector.cpp
    Entity.cpp
    InputAffector.cpp
)
