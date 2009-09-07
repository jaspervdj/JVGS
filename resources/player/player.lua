require("resources/common")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

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

local events = {
    spawn = function()
        self:setBool("ready", true)
    end,

    die = function()
        common.gameOver()
    end,

    action = function()
        if self:isSet("weapon") and self:getBool("ready") then
            local weapon = self:get("weapon")
            if weapons[weapon] then weapons[weapon]() end
            self:setBool("ready", false)
        end
    end,

    timer = function()
        self:setBool("ready", true)
    end
}

local f = events[event:getType()]
if f then f() end
