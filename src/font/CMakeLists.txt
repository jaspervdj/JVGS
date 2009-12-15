# Set up include directories.
INCLUDE_DIRECTORIES(
    ${FREETYPE_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIRS}
)

ADD_LIBRARY( 
    font STATIC 
    Font.cpp
    FontManager.cpp
)

# Link to the following libraries
TARGET_LINK_LIBRARIES(
    font
    sketch
    ${FREETYPE_LIBRARIES}
    ${ZLIB_LIBRARIES}
)
