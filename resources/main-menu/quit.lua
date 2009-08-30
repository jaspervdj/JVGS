require("resources/common")
local event = jvgslua.EntityEvent_getEvent()

local events = {
    collision = function()
        local im = jvgslua.InputManager_getInstance()
        im:sendQuitEvent()
    end
}

local f = events[event:getType()]
if f then f() end
