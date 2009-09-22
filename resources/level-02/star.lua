require("resources/effects/effects")
require("resources/events")
events.trigger{
    collision = function()
        common.nextLevel("resources/level-03/level-03.xml")
    end
}
