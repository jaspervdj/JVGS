require("resources/effects/effects")
require("resources/events")
events.trigger{
    collision = function()
        effects.staticText(jvgslua.Vector2D(1040, 170),
                "spacebar to jump")
        self:setGarbage()
    end
}
