require("resources/common")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

events = {
    collision = function()
        local collider = event:getCollider()
        if collider:getId() == "player" then
            local sprite = jvgslua.Sprite("resources/player/clock-sprite.xml")
            collider:setSprite(sprite)
            collider:set("weapon", "clock")
            self:setGarbage()
        end
    end
}

f = events[event:getType()]
if f then f() end
