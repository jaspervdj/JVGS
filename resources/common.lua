require("resources/effects/effects")

common = {
    -- Returns winner, loser
    fight = function(enemy, collider)
        if collider:getId() ~= "player" then return nil, nil end
        if enemy:getBool("dead") or collider:getBool("dead") then
            return nil, nil
        end

        local y = collider:getPosition():getY() + collider:getRadius():getY()
        if enemy:getPosition():getY() > y then
            return collider, enemy
        else
            return enemy, collider
        end
    end,

    kill = function(e)
        if e:getBool("invulnerable") then return end

        -- Kill him
        e:setBool("dead", true)

        -- Drop him.
        e:setController(nil)
        local positioner = jvgslua.NaivePositioner(e)
        e:setPositioner(positioner)
        local velocity = jvgslua.Vector2D(0, 2 * e:getSpeed())
        e:setVelocity(velocity)

        -- Effects.
        effects.text(e:getPosition())
        effects.stars(e:getPosition())

        -- Invert effect when player.
        if e:getId() == "player" then
            local em = jvgslua.EffectManager_getInstance()
            local effect = jvgslua.InvertEffect()
            em:addEffect(effect)
        end
    end,

    gameOver = function()
        local lm = jvgslua.LevelManager_getInstance()
        lm:queueLevel("resources/levels/menu.xml")
    end
}
