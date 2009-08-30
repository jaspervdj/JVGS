require("resources/effects/effects")
local event = jvgslua.EntityEvent_getEvent()

local events = {
    collision = function()
        common.nextLevel("resources/level-02/level-02.xml")
    end
}

local f = events[event:getType()]
if f then f() end
