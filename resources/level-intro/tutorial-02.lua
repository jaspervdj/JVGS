events.trigger{
    collision = function(self, event)
        effects.staticText(jvgslua.Vector2D(1040, 170),
                "spacebar to jump")
        self:setGarbage()
    end
}
