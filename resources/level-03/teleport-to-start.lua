events.trigger{
    collision = function(self, event)
        local player = self:getLevel():getEntityById("player")
        player:setPosition(jvgslua.Vector2D(2425, 1340))
    end
}
