common = {}

-- Returns winner, loser
function common.fight(enemy, collider)
    if collider:getId() ~= "player" then return nil, nil end
    if enemy:getBool("dead") or collider:getBool("dead") then
        return nil, nil
    end

    local em = jvgslua.EffectManager_getInstance()
    local effect = jvgslua.TextEffect("Whack!", enemy:getPosition())
    em:addEffect(effect)

    local y = collider:getPosition():getY() + collider:getRadius():getY()
    if enemy:getPosition():getY() > y then
        return collider, enemy
    else
        return enemy, collider
    end
end

function common.kill(e)
    if e:getBool("invulnerable") then return end

    -- Kill him
    e:setBool("dead", true)

    -- Drop him.
    e:setController(nil)
    local positioner = jvgslua.NaivePositioner(e)
    e:setPositioner(positioner)
    local velocity = jvgslua.Vector2D(0, 2 * e:getSpeed())
    e:setVelocity(velocity)

    -- Effect when player.
    if e:getId() == "player" then
        local em = jvgslua.EffectManager_getInstance()
        local effect = jvgslua.InvertEffect()
        em:addEffect(effect)
    end
end

function common.gameOver()
    local lm = jvgslua.LevelManager_getInstance()
    lm:queueLevel("resources/levels/menu.xml")
end
