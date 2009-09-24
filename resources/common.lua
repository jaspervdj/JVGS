require("resources/effects/effects")
module("common", package.seeall)

-- Returns winner, loser
function fight(enemy, collider)
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
end

function impossibleFight(enemy, collider)
    if collider:getId() ~= "player" then return nil end
    if enemy:getBool("dead") or collider:getBool("dead") then
        return nil
    end

    return enemy, collider
end

function kill(e)
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

    -- Play sound.
    if e:isSet("die-sound") then
        local am = jvgslua.AudioManager_getInstance()
        am:playSound(e:get("die-sound"))
    end

    -- Other things when player.
    if e:getId() == "player" then
        local em = jvgslua.EffectManager_getInstance()
        local effect = jvgslua.InvertEffect()
        em:addEffect(effect)
        local lm = jvgslua.LevelManager_getInstance()
        lm:setTimeFactor(0.2)
        -- Limit falling sequence.
        e:setTimer(1000)
    end
end

function gameOver()
    local lm = jvgslua.LevelManager_getInstance()
    lm:queueLevel("resources/main-menu/main-menu.xml")
end

function nextLevel(fileName)
    local pm = jvgslua.PersistenceManager_getInstance()
    pm:set("level", fileName)
    local lm = jvgslua.LevelManager_getInstance()
    lm:queueLevel(fileName)
end

function continue()
    local pm = jvgslua.PersistenceManager_getInstance()
    local fileName
    if pm:isSet("level") then
        fileName = pm:get("level")
    else
        fileName = "resources/level-01/level-01.xml"
    end

    local lm = jvgslua.LevelManager_getInstance()
    lm:queueLevel(fileName)
end
