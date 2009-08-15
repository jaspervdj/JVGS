# Set up include directories.
INCLUDE_DIRECTORIES(
    ${FREETYPE_INCLUDE_DIRS}
)

ADD_LIBRARY( 
    font STATIC 
    Font.cpp
)

# Link to the following libraries
TARGET_LINK_LIBRARIES(
    font
    sketch
    ${FREETYPE_LIBRARIES}
)
