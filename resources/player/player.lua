require("resources/common")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

local weapons = {
    knife = function()
        local level = self:getLevel()
        local entity = jvgslua.Entity("resources/knife/knife.xml", level)
        if self:isFacingRight() then
            entity:setVelocity(jvgslua.Vector2D(entity:getSpeed(), 0))
        else
            entity:setVelocity(jvgslua.Vector2D(-entity:getSpeed(), 0))
        end

        entity:setPosition(self:getPosition())
        level:addEntity(entity)
        self:setTimer(2000)

        local am = jvgslua.AudioManager_getInstance()
        am:playSound("resources/knife/throw.ogg")
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
