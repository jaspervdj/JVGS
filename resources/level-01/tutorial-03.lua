require("resources/effects/effects")
require("resources/events")
events.trigger{
    collision = function()
        effects.staticText(self:getPosition() + jvgslua.Vector2D(0, -100),
                "jump on enemies to kill them")
        self:setGarbage()
    end
}
