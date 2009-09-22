require("resources/common")
require("resources/events")
events.trigger{
    collision = function(self, event)
        local collider = event:getCollider()
        if collider:getId() == "player" then
            local sprite = jvgslua.Sprite("resources/player/clock-sprite.xml")
            collider:setSprite(sprite)
            collider:set("weapon", "clock")
            self:setGarbage()
        end
    end
}
