require("resources/common")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

local events = {
    die = function()
        common.gameOver()
    end,

    action = function()
        local pos = self:getPosition()
        print("(" .. pos:getX() .. ", " .. pos:getY() .. ")")

        if self:getBool("hat") then
            local level = self:getLevel()
            local bullet = jvgslua.Entity("resources/bullet/bullet.xml", level)
            if self:isFacingRight() then
                bullet:setVelocity(jvgslua.Vector2D(bullet:getSpeed(), 0))
            else
                bullet:setVelocity(jvgslua.Vector2D(-bullet:getSpeed(), 0))
            end

            bullet:setPosition(self:getPosition())
            level:addEntity(bullet)

            local am = jvgslua.AudioManager_getInstance()
            am:playSound("resources/sounds/shoot.ogg")
        end
    end
}

local f = events[event:getType()]
if f then f() end
