events.trigger{
    collision = function(self, event)
        if common.isPlayer(event:getCollider) then
        common.nextLevel("resources/level-06/level-06.xml")
        end
    end
}
