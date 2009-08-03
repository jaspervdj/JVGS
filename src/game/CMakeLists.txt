INCLUDE_DIRECTORIES(
    ${SDL_INCLUDE_DIR}
)

ADD_LIBRARY( 
    game STATIC 
    Affector.cpp
    CollisionResponsePositioner.cpp
    Controller.cpp
    Entity.cpp
    InputController.cpp
    Positioner.cpp
)
