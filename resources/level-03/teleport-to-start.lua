require("resources/effects/effects")
local event = jvgslua.EntityEvent_getEvent()

local events = {
    collision = function()
        local player = event:getSource():getLevel():getEntityById("player")
        player:setPosition(jvgslua.Vector2D(4620, 4400))
    end
}

local f = events[event:getType()]
if f then f() end
