require("resources/common")
local event = jvgslua.EntityEvent_getEvent()

if event:getType() == "spawn" then
    event:getSource():setBool("invulnerable", true)
end

if event:getType() == "collision" then
    local collider = event:getCollider()
    if collider:getId() == "player" then
        local lm = jvgslua.LevelManager_getInstance()
        lm:queueLevel("resources/levels/level-01-end.xml")
    end
end
