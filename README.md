# Project Description

The Lys engine is developed using C++23 with support for both Clang and GCC. Additionally, the project only supports OpenGL 3.3 or higher.

# CMake Flags and Options

- -DUSE_DOUBLE

- -D_ALWAYS_INLINE_

- -D_FORCE_INLINE_

- -D_NDEBUG

# Setup

## Linux

```
sudo ./scripts/linux.sh
```

## Windows

While Windows support is constantly being worked on, it is not the main focus and thus may not work.

# Development

- CMake versions 3.28.3 or higher
- GCC-14 or Clang-18
- OpenGL 3.3 or higher

# Third-party dependencies

|           Usage           |                                    Library                                    |
|:-------------------------:|:-----------------------------------------------------------------------------:|
| Window management & input |                 [GLFW3](https://www.glfw.org/) (ZLib/LibPNG)                  |
|       OpenGL loader       | [GLEW](https://github.com/nigels-com/glew/tree/master) (Modified BSD License) |
|       Image loading       |              [stb_image](https://github.com/nothings/stb) (MIT)               |
|        Mathematics        |                  [GLM](https://github.com/g-truc/glm) (MIT)                   |
|           Fonts           |    [FreeType](https://download.savannah.gnu.org/releases/freetype/) (FTL)     |


https://github.com/jrouwe/JoltPhysics
https://github.com/ocornut/imgui