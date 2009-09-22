require("resources/effects/effects")
require("resources/events")
events.trigger{
    collision = function()
        local player = event:getSource():getLevel():getEntityById("player")
        player:setPosition(jvgslua.Vector2D(2425, 1340))
    end
}
