#pragma once

#include "LilyPad/core/math/vector2.hpp"

using namespace LilyPad;

Vector2 random_gradient(int xCoord, int yCoord);
float dot_grid_gradient(int gridX, int gridY, float pointX, float pointY);
float interpolate(float startValue, float endValue, float weight);
float perlin(float x, float y);
