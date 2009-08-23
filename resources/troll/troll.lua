require("resources/common")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

events = {}

function events.collision()
    local collider = event:getCollider()
    if self:getBool("dead") or collider:getBool("dead") then return end
    if collider:getId() == "player" then
        common.kill(collider)
    end
end

function events.die()
    local am = jvgslua.AudioManager_getInstance()
    am:playSound("resources/sounds/troll.ogg")
end


f = events[event:getType()]
if f then f() end
