require("resources/common")
require("resources/events")
events.trigger{
    collision = function()
        common.continue()
    end
}
