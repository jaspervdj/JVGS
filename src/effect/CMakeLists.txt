ADD_LIBRARY( 
    effect STATIC 
    ColorEffect.cpp
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
