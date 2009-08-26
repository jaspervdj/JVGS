ADD_LIBRARY( 
    effect STATIC 
    EffectManager.cpp
    InvertEffect.cpp
    Particle.cpp
    LifeEffect.cpp
    TextEffect.cpp
)

TARGET_LINK_LIBRARIES(
    effect font
)
