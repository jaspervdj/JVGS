events = {
    ["test"] = "foo",
    trigger = function(events)
        local event = jvgslua.EntityEvent_getEvent()
        local self = event:getSource()
        local f = events[event:getType()]
        if f then f(self, event) end
    end
}
