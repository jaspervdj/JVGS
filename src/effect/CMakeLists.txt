ADD_LIBRARY( 
    effect STATIC 
    EffectManager.cpp
    InvertEffect.cpp
    Particle.cpp
    LifeEffect.cpp
    TextEffect.cpp
    TimeEffect.cpp
)

TARGET_LINK_LIBRARIES(
    effect font
)
