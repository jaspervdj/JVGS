require("resources/events")
events.trigger{
    collision = function(self, event)
        local collider = event:getCollider()
        local winner, loser = common.fight(self, collider)
        if loser then common.kill(loser) end
    end
}
