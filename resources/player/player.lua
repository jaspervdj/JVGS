require("resources/common")
local event = jvgslua.EntityEvent_getEvent()

if event:getType() == "die" then
    common.gameOver()
end
