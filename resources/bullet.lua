event = jvgslua.EntityEvent_getEvent()
self = event:getSource()

events = {}
function events.die()
    local effect = jvgslua.TextEffect("Boom!", self:getPosition(), 2000, 0.1)
    local em = jvgslua.EffectManager_getInstance()
    em:addEffect(effect)
end

if events[event:getType()] then events[event:getType()]() end
