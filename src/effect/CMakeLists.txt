ADD_LIBRARY( 
    effect STATIC 
    EffectManager.cpp
    TextEffect.cpp
)

TARGET_LINK_LIBRARIES(
    effect font
)
