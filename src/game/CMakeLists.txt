INCLUDE_DIRECTORIES(
    ${SDL_INCLUDE_DIR}
)

ADD_LIBRARY( 
    game STATIC 
    Affector.cpp
    Animation.cpp
    Camera.cpp
    CameraFactory.cpp
    CollisionResponsePositioner.cpp
    Controller.cpp
    Entity.cpp
    FollowCamera.cpp
    InputController.cpp
    Positioner.cpp
    Sprite.cpp
    Level.cpp
)
