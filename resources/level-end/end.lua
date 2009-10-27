events.trigger{
    collision = function(self, event)
        local collider = event:getCollider()

        -- Player reached end, prepare for end.
        if common.isPlayer(collider) and self:getBool("girl-arrived") then
            local em = jvgslua.EffectManager_getInstance()
            local fe = jvgslua.FadeEffect(10000)
            collider:setController(nil)
            collider:setPositioner(nil)
            collider:setVelocity(jvgslua.Vector2D(0, 0))
            em:addEffect(fe)
            self:setTimer(10000)
            -- Hack to prevent future collisions
            self:setPosition(jvgslua.Vector2D(0, 0))

        -- Girl reached the end, wait for player.
        elseif collider:getId() == "girl" then
            collider:setController(nil)
            collider:setVelocity(jvgslua.Vector2D(0, 0))
            self:setBool("girl-arrived", true)
        end
    end,

    timer = function(self, event)
        common.gameOver()
    end
}
