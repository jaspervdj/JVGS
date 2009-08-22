require("resources/common")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

events = {}

function events:die()
    common.gameOver()
end

function events.action()
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
    end
end

f = events[event:getType()]
if f then f() end
