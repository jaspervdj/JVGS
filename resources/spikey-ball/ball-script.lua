events.trigger{
    collision = function(self, event)
        -- Only after being dropped
        if self:isCollisionChecker() then
            local collider = event:getCollider()
            common.kill(collider, true)
            effects.stars(self:getPosition(), 5)
            self:setGarbage()
        end
    end
}
