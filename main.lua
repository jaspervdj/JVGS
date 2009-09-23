local videoManager = jvgslua.VideoManager_getInstance()
videoManager:setVideoMode(jvgslua.Vector2D(600, 400), "jvgs")

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
levelManager:queueLevel("resources/main-menu/main-menu.xml")

levelManager:run()

pm:write("data.xml")
