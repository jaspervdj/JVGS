require("resources/modules/common")
require("resources/modules/jlib")
require("resources/modules/events")
require("resources/modules/effects")

-- Parse options and set video mode from that.
local options = jlib.parseOptions()
local videoManager = jvgslua.VideoManager_getInstance()
if options.width and options.height then
    videoManager:setVideoMode(jvgslua.Vector2D(options.width, options.height),
            "jvgs")
elseif options.fullscreen == "no" then
    videoManager:setVideoMode(jvgslua.Vector2D(640, 480), "jvgs")
else
    videoManager:setVideoMode("jvgs")
end
    

-- Warn when using global variables.
setmetatable(_G, {
    __newindex = function(table, key, value)
        print("Warning - setting global " .. key .. " to a " .. type(value))
        rawset(table, key, value)
    end
})

-- Set key configuration.
local ic = jvgslua.InputConfiguration_getConfiguration()
ic:setKey("jump", jvgslua.KEY_SPACE)
ic:setKey("action", jvgslua.KEY_LCTRL)
ic:setKey("left", jvgslua.KEY_LEFT)
ic:setKey("right", jvgslua.KEY_RIGHT)
ic:setKey("up", jvgslua.KEY_UP)
ic:setKey("down", jvgslua.KEY_DOWN)

-- Ensure persistence.
local pm = jvgslua.PersistenceManager_getInstance()
pm:load("data.xml")

-- Load a font
local font = jvgslua.Font("resources/font.ttf", 36)
local fontManager = jvgslua.FontManager_getInstance()
fontManager:addFont("regular", font)

local levelManager = jvgslua.LevelManager_getInstance()
levelManager:queueLevel("resources/level-main-menu/main-menu.xml")

levelManager:run()

pm:write("data.xml")
