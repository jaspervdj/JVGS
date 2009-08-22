videoManager = jvgslua.VideoManager_getInstance()
videoManager:setVideoMode(jvgslua.Vector2D(600, 400), "jvgs")

-- Load a font
font = jvgslua.Font("resources/font.ttf", 28)
fontManager = jvgslua.FontManager_getInstance()
fontManager:addFont("regular", font)

levelManager = jvgslua.LevelManager_getInstance()
levelManager:queueLevel("resources/levels/menu.xml")

levelManager:run()
