require("resources/effects/effects")
local event = jvgslua.EntityEvent_getEvent()

local events = {
    spawn = function()
        effects.staticText(jvgslua.Vector2D(420, 170),
                "arrow keys to walk")
    end
}

local f = events[event:getType()]
if f then f() end
