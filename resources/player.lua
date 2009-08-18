event = jvgslua.EntityEvent_getEvent()
self = event:getSource()

events = {}
function events.spawn()
    local am = jvgslua.AudioManager_getInstance()
    am:playMusic("resources/title.ogg")
end

function events.die()
    local am = jvgslua.AudioManager_getInstance()
    am:playSound("resources/die.ogg")
end

function events.action()
    local level = self:getLevel()
    local bullet = jvgslua.Entity("resources/bullet.xml", level)
    local speed = self:isFacingRight() and self:getSpeed() or -self:getSpeed()
    bullet:setVelocity(jvgslua.Vector2D(speed, 0))
    bullet:setPosition(self:getPosition())
    level:addEntity(bullet)
end

if events[event:getType()] then events[event:getType()]() end
