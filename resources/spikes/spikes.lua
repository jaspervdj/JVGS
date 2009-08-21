require("resources/common")
local event = jvgslua.EntityEvent_getEvent()

if event:getType() == "collision" then
    local collider = event:getCollider()
    common.kill(collider) 
end
