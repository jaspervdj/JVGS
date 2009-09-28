#!/bin/echo Run this script through jvgs: 

-- Get manager references.
local sm = jvgslua.ScriptManager_getInstance()
local vm = jvgslua.VideoManager_getInstance()
local tm = jvgslua.TimeManager_getInstance()
local im = jvgslua.InputManager_getInstance()

-- Check arguments.
if sm:getNumberOfArguments() < 3 then
    print("Usage: " .. sm:getArgument(0) .. " " ..
            sm:getArgument(1) .. " file")
    os.exit(1)
end

-- Dummy video mode.
vm:setVideoMode(jvgslua.Vector2D(200, 200), "Loading...")

-- Load file.
local sketch = jvgslua.Sketch(sm:getArgument(2))

-- Set video mode.
vm:setVideoMode(sketch:getSize(),
        sm:getArgument(2) .. " - jvgs file viewer")

-- Simple main loop.
while not im:hasQuitEvent() do
    im:update(10)
    vm:clear()
    sketch:render()
    vm:flip()
    tm:sleep(10)
end
