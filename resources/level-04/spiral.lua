require("resources/effects/effects")
require("resources/events")
events.trigger{
    collision = function(self, event)
        common.nextLevel("resources/level-05/level-05.xml")
    end
}
