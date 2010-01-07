# 1. Contents

1. Contents
2. Notes
3. Dependencies
4. Compiling
5. Running

# 2. Notes

The sounds are not included on github. Get them from the sourceforge mirrors.
Actually, get the whole package from sourceforge unless you want an unstable
release.

# 3. Dependencies

- A sane compiler.
- CMake (>= 2.6)
- SDL (>= 1.2)
- SDL_mixer (>= 1.2)
- FreeType (recent version)
- Swig (recent version)

# 4. Compiling

cd into the jvgs folder, and then:

    cmake .
    make

# 5. Running

To execute run the game, use

    ./src/jvgs

By default, it runs the game in fullscreen mode. If you do not want this, you
can run it like this in windowed mode:

    ./src/jvgs main.lua --width 800 --height 600

JVGS will remember the most recent video mode. To put it in fullscreen mode
again, use:

    ./src/jvgs main.lua --fullscreen yes
