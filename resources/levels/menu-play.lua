local event = jvgslua.EntityEvent_getEvent()
if event:getType() == "collision" then
    print("Let's play!")
end
