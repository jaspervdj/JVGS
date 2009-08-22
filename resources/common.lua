common = {}
function common.enemyPlayerCollision(e, p)
    if e:getBool("dead") or p:getBool("dead") then return end

    local y = p:getPosition():getY() + p:getRadius():getY()
    local loser = e:getPosition():getY() < y and p or e

    common.kill(loser)
end

function common.kill(e)
    -- Drop him.
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
