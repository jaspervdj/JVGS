event = jvgslua.EntityEvent_getEvent()
self = event:getSource()

events = {}
function events.collision()
    local collider = event:getCollider()

    if collider:isSet("dead") or self:isSet("dead") then
        return
    end

    -- Player should be ABOVE collider
    local y = self:getPosition():getY() - self:getRadius():getY()

    local loser
    if collider:getPosition():getY() < y then
        loser = self
        if collider:isSet("points") then
            collider:set("points", collider:get("points") + 5)
        else
            collider:set("points", 5)
        end
    else
        loser = collider
    end

    local gravity = loser:getPositioner():getGravity()
    local naive = jvgslua.NaivePositioner(loser)
    naive:setGravity(gravity)
    loser:setPositioner(naive)
    loser:set("dead", "1")

    local effect = jvgslua.TextEffect("Whack!", loser:getPosition(), 2000)
    local em = jvgslua.EffectManager_getInstance()
    em:addEffect(effect)
end

function events.die()
    print("AAAaaaaarghhh!")
    print(self:getLevel():getEntityById("player"):get("points"))
end

if events[event:getType()] then events[event:getType()]() end
