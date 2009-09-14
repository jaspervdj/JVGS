require("resources/effects/effects")
require("resources/common")
local event = jvgslua.EntityEvent_getEvent()
local self = event:getSource()

local events = {
    collision = function()
        local level = self:getLevel()
        local player = level:getEntityById("player")
        local crowns = player:isSet("crowns") and player:get("crowns") or 0
        crowns = crowns + 1
        player:set("crowns", crowns)
        effects.staticText(self:getPosition() + jvgslua.Vector2D(0, -100),
                crowns .. " out of 4")
        self:setGarbage() 

        if tonumber(player:get("crowns")) >= 4 then
            common.nextLevel("resources/level-04/level-04.xml")
        end
    end
}

local f = events[event:getType()]
if f then f() end
