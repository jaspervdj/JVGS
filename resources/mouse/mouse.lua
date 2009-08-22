require("resources/common")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

events = {}

function events.collision()
    local collider = event:getCollider()
    local winner, loser = common.fight(self, collider)
    if loser then common.kill(loser) end
end

f = events[event:getType()]
if f then f() end
