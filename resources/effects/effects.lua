require("resources/jlib")

effects = {
    textEffects = {"Whack!", "Splash!", "Pow!"},

    stars = function(position)
        local sm = jvgslua.SketchManager_getInstance()
        local em = jvgslua.EffectManager_getInstance()
        local star = sm:getSketch("resources/effects/star.svg")

        local gravity = jvgslua.Vector2D(0, 0.003)

        for i = 1, math.random(10, 20) do
            local velocity = jvgslua.Vector2D_fromPolar(1 + 1 * math.random(),
                    math.random() * 360)

            particle = jvgslua.Particle(star, 1000 + 3000 * math.random(),
                    position, velocity, gravity)
            em:addEffect(particle)
        end
    end,

    text = function(position, str)
        str = str or jlib.randomItem(effects.textEffects)
        local em = jvgslua.EffectManager_getInstance()
        local e = jvgslua.TextEffect(str, position, 1000 + 1000 * math.random(),
                0.1 + 0.1 * math.random(), 360 * math.random())
        em:addEffect(e)
    end,

    staticText = function(position, str)
        local em = jvgslua.EffectManager_getInstance()
        local e = jvgslua.TextEffect(str, position, 0, 0, 0)
        em:addEffect(e)
    end
}
