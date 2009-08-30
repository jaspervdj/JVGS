require("resources/common")
local event = jvgslua.EntityEvent_getEvent()

local events = {
    collision = function()
        common.continue()
    end
}

local f = events[event:getType()]
if f then f() end
