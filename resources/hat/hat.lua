require("resources/common")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

events = {}

function events.collision()
    local collider = event:getCollider()
    if collider:getId() == "player" then
        local hatSprite = jvgslua.Sprite("resources/player/hat-sprite.xml")
        collider:setSprite(hatSprite)
        collider:setBool("hat", true)
        self:setGarbage()

        local am = jvgslua.AudioManager_getInstance()
        am:playSound("resources/sounds/hat.ogg")
    end
end

f = events[event:getType()]
if f then f() end
