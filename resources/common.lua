common = {}
function common.kill(e)
    -- Drop him.
    local positioner = jvgslua.NaivePositioner(e)
    e:setPositioner(positioner)
    e:set("dead", 1)

    local am = jvgslua.AudioManager_getInstance()
    am:playSound("resources/sounds/die-01.ogg")
end

function common.gameOver()
    local lm = jvgslua.LevelManager_getInstance()
    lm:queueLevel("resources/levels/menu.xml")
end
