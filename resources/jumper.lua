require("resources/common")
local event = jvgslua.EntityEvent_getEvent()

if event:getType() == "collision" then
    local collider = event:getCollider()
    if not collider:getBool("dead") then
        local velocity = jvgslua.Vector2D(0, -1.0)
        collider:setVelocity(velocity)
    end
end
