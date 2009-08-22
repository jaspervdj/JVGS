common = {}
function common.enemyPlayerCollision(e, p)
    if e:getBool("dead") or p:getBool("dead") then return end

    local y = p:getPosition():getY() + p:getRadius():getY()
    local loser
    if e:getPosition():getY() > y then
        loser = e
    else
        loser = p
    end

    common.kill(loser)
end

function common.kill(e)
    -- Drop him.
    if e:getBool("invulnerable") then return end

    local positioner = jvgslua.NaivePositioner(e)
    e:setController(nil)
    e:setPositioner(positioner)
    e:setBool("dead", true)

    local velocity = jvgslua.Vector2D(0, e:getSpeed())
    e:setVelocity(velocity)
end

function common.gameOver()
    local lm = jvgslua.LevelManager_getInstance()
    lm:queueLevel("resources/levels/menu.xml")
end
