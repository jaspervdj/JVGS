local event = jvgslua.EntityEvent_getEvent()
if event:getType() == "collision" then
    local inputManager = jvgslua.InputManager_getInstance()
    inputManager:sendQuitEvent()
end
