# Project Description

**The project is currently in the midst of moving towards a file-based scene heirarchy, and as such, is not usable until a complete scene-parser is developed!**

The Lys engine is developed using C++23 with support for both Clang and GCC. Additionally, the project only supports OpenGL 3.3 or higher.

# CMake Flags and Options

- -DUSE_DOUBLE

- -DALWAYS_INLINE

- -DFORCE_INLINE

- -DVULKAN

- -DOPENGL

# Setup

`git submodule update --init --recursive`

## Linux

```
sudo ./scripts/linux.sh
```

## Other Platforms

Currently no other platforms are supported and will not work at this time.

# Build

`cmake -B build -DCMAKE_C_COMPILER=/usr/bin/gcc-14 -DCMAKE_CXX_COMPILER=/usr/bin/g++-14 -DBUILD_TESTS=ON`
`make`

# Development

- CMake versions 3.28.3 or higher
- GCC-14 or Clang-18
- OpenGL 3.3 or higher

# Third-party dependencies

|           Usage           |                                    Library                                    |
| :-----------------------: | :---------------------------------------------------------------------------: |
| Window management & input |                 [GLFW3](https://www.glfw.org/) (ZLib/LibPNG)                  |
|       OpenGL loader       | [GLEW](https://github.com/nigels-com/glew/tree/master) (Modified BSD License) |
|       Image loading       |              [stb_image](https://github.com/nothings/stb) (MIT)               |
|        Mathematics        |                  [GLM](https://github.com/g-truc/glm) (MIT)                   |
|           Fonts           |    [FreeType](https://download.savannah.gnu.org/releases/freetype/) (FTL)     |
|          Physics          |              [MIT](https://github.com/jrouwe/JoltPhysics) (MIT)               |
|            GUI            |                 [MIT](https://github.com/ocornut/imgui) (MIT)                 |
