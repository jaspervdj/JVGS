events.trigger{
    collision = function(self, event)
        local collider = event:getCollider()
        if common.isPlayer(collider) then
            local crowns = collider:isSet("crowns") and collider:get("crowns") or 0
            crowns = crowns + 1
            collider:set("crowns", crowns)
            effects.staticText(self:getPosition() + jvgslua.Vector2D(0, -100),
                    crowns .. " out of 4")
            self:setGarbage() 

            if collider:get("crowns") >= 4 then
                common.nextLevel("resources/level-04/level-04.xml")
            end
        end
    end
}
