local videoManager = jvgslua.VideoManager_getInstance()
videoManager:setVideoMode(jvgslua.Vector2D(600, 400), "jvgs")

-- Ensure persistence.
local pm = jvgslua.PersistenceManager_getInstance()
pm:load("data.xml")

-- Play soundtrack
local am = jvgslua.AudioManager_getInstance()
am:playMusic("resources/soundtrack.ogg")

-- Load a font
local font = jvgslua.Font("resources/font.ttf", 36)
local fontManager = jvgslua.FontManager_getInstance()
fontManager:addFont("regular", font)

local levelManager = jvgslua.LevelManager_getInstance()
levelManager:queueLevel("resources/main-menu/main-menu.xml")

levelManager:run()

pm:write("data.xml")
