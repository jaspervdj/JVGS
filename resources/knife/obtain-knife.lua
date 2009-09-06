require("resources/common")
require("resources/effects/effects")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

events = {
    collision = function()
        local collider = event:getCollider()
        if collider:getId() == "player" then
            local sprite = jvgslua.Sprite("resources/player/knife-sprite.xml")
            collider:setSprite(sprite)
            collider:set("weapon", "knife")
            self:setGarbage()
            effects.staticText(self:getPosition() + jvgslua.Vector2D(0, -100),
                    "left ctrl to use weapons")
        end
    end
}

f = events[event:getType()]
if f then f() end
