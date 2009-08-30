require("resources/effects/effects")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

local events = {
    collision = function()
        effects.staticText(self:getPosition() + jvgslua.Vector2D(0, -100),
                "jump on enemies to kill them")
        self:setGarbage()
    end
}

local f = events[event:getType()]
if f then f() end
