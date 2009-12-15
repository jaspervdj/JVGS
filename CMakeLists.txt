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

##########################
# SDL_mixer
##########################
FIND_PACKAGE(SDL_mixer)
IF( SDLMIXER_FOUND )
    # take a lucky guess
    IF(${SDLMIXER_INCLUDE_DIR} MATCHES "NOTFOUND")
        SET(SDLMIXER_INCLUDE_DIR ${SDL_INCLUDE_DIR})
    ENDIF(${SDLMIXER_INCLUDE_DIR} MATCHES "NOTFOUND")
        MESSAGE( STATUS "SDL_mixer has been found:" )
        MESSAGE( STATUS "\tCFLAGS : ${SDLMIXER_INCLUDE_DIR}" )
        MESSAGE( STATUS "\tLDFLAGS: ${SDLMIXER_LIBRARY}" )
ELSE( SDLMIXER_FOUND )
    SET( SDLMIXER_INCLUDE_DIR NOTFOUND )
    SET( SDLMIXER_LIBRARY NOTFOUND )
    MESSAGE( STATUS "SDL_mixer is required" )
ENDIF(SDLMIXER_FOUND)

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

#######################
# Lua
#######################
FIND_PACKAGE(Lua51)
IF(LUA51_FOUND)
    MESSAGE( STATUS "Lua has been found:" )
    MESSAGE( STATUS "\tCFLAGS : ${LUA_INCLUDE_DIR}" )
    MESSAGE( STATUS "\tLDFLAGS: ${LUA_LIBRARIES}" )
ELSE(LUA51_FOUND)
    SET( LUA_INCLUDE_DIR NOTFOUND )
    SET( LUA_LIBRARIES NOTFOUND )
    MESSAGE( STATUS "Lua is required" )
ENDIF(LUA51_FOUND)

#######################
# zlib
#######################
FIND_PACKAGE(ZLIB)
IF(ZLIB_FOUND)
    MESSAGE( STATUS "zlib has been found:" )
    MESSAGE( STATUS "\tCFLAGS : ${ZLIB_INCLUDE_DIRS}" )
    MESSAGE( STATUS "\tLDFLAGS: ${ZLIB_LIBRARIES}" )
ELSE(ZLIB_FOUND)
    SET( ZLIB_INCLUDE_DIRS NOTFOUND )
    SET( ZLIB_LIBRARIES NOTFOUND )
    MESSAGE( STATUS "zlib is required")
ENDIF(ZLIB_FOUND)

#######################
# Freetype
#######################
FIND_PACKAGE(Freetype)
IF(FREETYPE_INCLUDE_DIRS)
    MESSAGE( STATUS "Freetype has been found:" )
    MESSAGE( STATUS "\tCFLAGS : ${FREETYPE_INCLUDE_DIRS}" )
    MESSAGE( STATUS "\tLDFLAGS: ${FREETYPE_LIBRARIES}" )
ELSE(FREETYPE_INCLUDE_DIRS)
    SET( FREETYPE_INCLUDE_DIRS NOTFOUND )
    SET( FREETYPE_LIBRARIES NOTFOUND )
    MESSAGE( STATUS "Freetype is required" )
ENDIF(FREETYPE_INCLUDE_DIRS)

#######################
# Swig
#######################
FIND_PACKAGE(SWIG)
IF(SWIG_FOUND)
    MESSAGE( STATUS "SWIG has been found:" )
    MESSAGE( STATUS "\tSWIG : ${SWIG_EXECUTABLE}" )
ELSE(SWIG_FOUND)
    MESSAGE( STATUS "SWIG is required" )
ENDIF(SWIG_FOUND)

# Continue for subdirectories.
ADD_SUBDIRECTORY(src)

# Documentation
ADD_CUSTOM_TARGET(
    doxy
    doxygen Doxyfile
)
