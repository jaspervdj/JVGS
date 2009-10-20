#!/bin/echo Run this script through jvgs: 

-- Get manager references.
local scriptManager = jvgslua.ScriptManager_getInstance()
local videoManager = jvgslua.VideoManager_getInstance()
local timeManager = jvgslua.TimeManager_getInstance()
local inputManager = jvgslua.InputManager_getInstance()
local sketchManager = jvgslua.SketchManager_getInstance()

local border = jvgslua.Vector2D(10, 10)

-- Check arguments.
if scriptManager:getNumberOfArguments() < 3 then
    print("Usage: " .. scriptManager:getArgument(0) .. " " ..
            scriptManager:getArgument(1) .. " file")
    os.exit(1)
end

-- Dummy video mode.
videoManager:setVideoMode(jvgslua.Vector2D(200, 200), "Loading...")

-- Load file.
local sketch = sketchManager:getSketch(scriptManager:getArgument(2))

-- Set video mode.
videoManager:setVideoMode(sketch:getSize() + border * 2,
        scriptManager:getArgument(2) .. " - jvgs file viewer")

-- SinputManagerple main loop.
while not inputManager:hasQuitEvent() do
    inputManager:update(10)
    videoManager:clear()
    videoManager:identity()
    videoManager:translate(border)
    sketch:render()
    videoManager:flip()
    timeManager:sleep(10)
end
