require("resources/common")
require("resources/events")

-- Trigger functions for the different weapons.
local weapons = {
    knife = function()
        local level = self:getLevel()
        local entity = jvgslua.Entity("resources/knife/knife.xml", level)

        local velocity = jvgslua.Vector2D_fromPolar(entity:getSpeed(),
                math.random() * 20 - 10)

        if not self:isFacingRight() then
            velocity:setX(-velocity:getX())
        end

        entity:setPosition(self:getPosition())
        entity:setVelocity(velocity)
        level:addEntity(entity)
        self:setTimer(2000)

        local am = jvgslua.AudioManager_getInstance()
        am:playSound("resources/knife/throw.ogg")
    end,

    clock = function()
        local em = jvgslua.EffectManager_getInstance()
        local te = jvgslua.TimeEffect(0.2, 1000)
        em:addEffect(te)
        self:setTimer(2000)
    end
}

events.trigger{
    spawn = function(self, event)
        self:setBool("ready", true)
    end,

    die = function(self, event)
        common.gameOver()
    end,

    action = function(self, event)
        print(string.format("<point x=\"%.0f\" y=\"%.0f\" \/>",
                self:getPosition():getX(), self:getPosition():getY()))

        if self:isSet("weapon") and self:getBool("ready") then
            local weapon = self:get("weapon")
            if weapons[weapon] then weapons[weapon]() end
            self:setBool("ready", false)
        end
    end,

    timer = function(self, event)
        if self:getBool("dead") then
            -- Falling sequence limit reached.
            common.gameOver()
        else
            self:setBool("ready", true)
        end
    end
}
