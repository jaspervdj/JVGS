require("resources/common")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

events = {
    spawn = function()
        self:setTimer(500)
    end,

    collision = function()
        local collider = event:getCollider()
        if collider:getId() ~= "player" then
            common.kill(collider)
            self:setGarbage()
        end
    end,

    timer = function()
        self:setGarbage()
    end
}

f = events[event:getType()]
if f then f() end
