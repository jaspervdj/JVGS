events.trigger{
    collision = function(self, event)
        local collider = event:getCollider()
        common.kill(collider, true)
    end
}
