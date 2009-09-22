require("resources/effects/effects")
require("resources/events")
events.trigger{
    spawn = function()
        effects.staticText(jvgslua.Vector2D(420, 170),
                "arrow keys to walk")
    end
}
