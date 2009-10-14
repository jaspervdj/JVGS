events.trigger{
    collision = function(self, event)
        if common.isPlayer(event:getCollider()) then
            common.nextLevel("resources/level-03/level.xml")
        end
    end
}
