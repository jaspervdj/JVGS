require("resources/effects/effects")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

local events = {
    collision = function()
        effects.staticText(jvgslua.Vector2D(1040, 170),
                "spacebar to jump")
        self:setGarbage()
    end
}

local f = events[event:getType()]
if f then f() end
