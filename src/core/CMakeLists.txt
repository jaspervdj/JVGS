ADD_LIBRARY( 
    core SHARED 
    LogManager.cpp
    ScriptManager.cpp
)

TARGET_LINK_LIBRARIES(
    core
    ${LUA_LIBRARIES}
)
