event = jvgslua.EntityEvent_getEvent()
self = event:getSource()

events = {}
function events.collision()
    print("You touched a minimalist.")
end

if events[event:getType()] then events[event:getType()]() end
