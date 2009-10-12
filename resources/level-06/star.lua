events.trigger{
    collision = function(self, event)
        if common.isPlayer(event:getCollider()) then
            common.nextLevel("resources/level-07/level-07.xml")
        end
    end
}
