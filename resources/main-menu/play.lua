require("resources/common")
require("resources/events")
events.trigger{
    collision = function(self, event)
        common.continue()
    end
}
