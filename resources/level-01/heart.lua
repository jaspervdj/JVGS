require("resources/effects/effects")
require("resources/events")
events.trigger{
    collision = function(self, event)
        common.nextLevel("resources/level-02/level-02.xml")
    end
}
