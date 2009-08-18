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

if events[event:getType()] then events[event:getType()]() end
