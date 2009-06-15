##########################
# GENERAL OPTIONS
##########################
# We need 2.6 because cmake has freetype2 support from then onwards.
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(JVGS)

##########################
# SDL
##########################
FIND_PACKAGE(SDL)
IF(SDL_FOUND)
    MESSAGE( STATUS "SDL has been found:" )
    MESSAGE( STATUS "\tCFLAGS : ${SDL_INCLUDE_DIR}" )
    MESSAGE( STATUS "\tLDFLAGS: ${SDL_LIBRARY}" )
ELSE(SDL_FOUND)
    SET( SDL_INCLUDE_DIR NOTFOUND )
    SET( SDL_LIBRARY NOTFOUND )
    MESSAGE( STATUS "SDL is required")
ENDIF(SDL_FOUND)

#######################
# OpenGL
#######################
FIND_PACKAGE(OpenGL)
IF(OPENGL_INCLUDE_DIR)
    MESSAGE( STATUS "OpenGL has been found:" )
    MESSAGE( STATUS "\tCFLAGS : ${OPENGL_INCLUDE_DIR}" )
    MESSAGE( STATUS "\tLDFLAGS: ${OPENGL_LIBRARY}" )
ELSE(OPENGL_INCLUDE_DIR)
    SET( OPENGL_INCLUDE_DIR NOTFOUND )
    SET( OPENGL_LIBRARY NOTFOUND )
    MESSAGE( STATUS "OpenGL is required" )
ENDIF(OPENGL_INCLUDE_DIR)

# Continue for subdirectories.
ADD_SUBDIRECTORY(src)
