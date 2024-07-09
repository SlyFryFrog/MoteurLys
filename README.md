# Project Description

The LilyPad engine is developed using C++17 with support for both Clang and GCC. Additionally, the project only supports OpenGL 3.3 or higher.

# Setup

## Linux

```
sudo apt update
sudo apt-get install libgl1-mesa-dev libglew-dev libglfw3-dev
```

## Windows

# Development

- CMake versions 3.20 or higher
- GCC or Clang
- OpenGL 3.3 or higher

# Third-party dependencies

|           Usage           |                                    Library                                    |
|:-------------------------:|:-----------------------------------------------------------------------------:|
| Window management & input |                 [GLFW3](https://www.glfw.org/) (ZLib/LibPNG)                  |
|       OpenGL loader       | [GLEW](https://github.com/nigels-com/glew/tree/master) (Modified BSD License) |
|       Image loading       |              [stb_image](https://github.com/nothings/stb) (MIT)               |
|        Mathematics        |                  [GLM](https://github.com/g-truc/glm) (MIT)                   |