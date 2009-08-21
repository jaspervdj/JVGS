local event = jvgslua.EntityEvent_getEvent()
if event:getType() == "collision" then
    local lm = jvgslua.LevelManager_getInstance()
    lm:queueLevel("resources/levels/level-01.xml")
end
