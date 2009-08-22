require("resources/common")
local event = jvgslua.EntityEvent_getEvent()

if event:getType() == "collision" then
    local collider = event:getCollider()
    if not collider:getBool("dead") then
        common.kill(collider) 
    end
end
