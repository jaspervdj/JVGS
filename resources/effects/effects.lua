effects = {
    stars = function(position)
        local sm = jvgslua.SketchManager_getInstance()
        local em = jvgslua.EffectManager_getInstance()
        local star = sm:getSketch("resources/effects/star.svg")

        local gravity = jvgslua.Vector2D(0, 0.003)

        for i = 1, math.random(10, 20) do
            local velocity = jvgslua.Vector2D_fromPolar(1 + 3 * math.random(),
                    math.random() * math.pi * 2)

            particle = jvgslua.Particle(star, 1000 + 3000 * math.random(),
                    position, velocity, gravity)
            em:addEffect(particle)
        end
    end
}
