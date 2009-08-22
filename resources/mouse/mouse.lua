require("resources/common")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

events = {}

function events.collision()
    local collider = event:getCollider()
    if collider:getId() == "player" then
        common.enemyPlayerCollision(self, collider)
    end
end

f = events[event:getType()]
if f then f() end
