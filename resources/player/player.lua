event = jvgslua.EntityEvent_getEvent()
self = event:getSource()

events = {}

if events[event:getType()] then events[event:getType()]() end
