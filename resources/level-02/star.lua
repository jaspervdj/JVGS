require("resources/effects/effects")
require("resources/common")
local event = jvgslua.EntityEvent_getEvent()

local events = {
    collision = function()
        common.nextLevel("resources/level-03/level-03.xml")
    end
}

local f = events[event:getType()]
if f then f() end
