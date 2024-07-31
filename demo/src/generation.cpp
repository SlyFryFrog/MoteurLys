#include "generation.hpp"

#include <cmath>

using namespace LilyPad;

Vector2 random_gradient(const int xCoord, const int yCoord)
{
	constexpr unsigned totalBits = 8 * sizeof(unsigned);
	constexpr unsigned halfBits = totalBits / 2;
	unsigned xHash = xCoord, yHash = yCoord;

	// Use large prime numbers for hashing
	xHash *= 3284157443;

	// Mix xHash and yHash
	yHash ^= xHash << halfBits | xHash >> (totalBits - halfBits);
	yHash *= 1911520717;

	// Final mixing of xHash and yHash
	xHash ^= yHash << halfBits | yHash >> (totalBits - halfBits);
	xHash *= 2048419325;

	const double random = xHash * (3.14159265 / ~(~0u >> 1));

	// Convert to angle and compute the gradient vector
	return {static_cast<float>(sin(random)), static_cast<float>(cos(random))};
}

float dot_grid_gradient(const int gridX, const int gridY, const float pointX, const float pointY)
{
	Vector2 gradient = random_gradient(gridX, gridY);
	Vector2 distance = {pointX - static_cast<float>(gridX), pointY - static_cast<float>(gridY)};
	return gradient.x * distance.x + gradient.y * distance.y;
}

float interpolate(const float startValue, const float endValue, const float weight)
{
	// Perform smoothstep interpolation
	return (endValue - startValue) * (3.0f - weight * 2.0f) * weight * weight + startValue;
}

float perlin(float x, float y)
{
	// Determine grid cell corner coordinates
	const int x0 = static_cast<int>(x);
	const int y0 = static_cast<int>(y);
	const int x1 = x0 + 1;
	const int y1 = y0 + 1;

	// Compute interpolation weights
	const float weightX = x - static_cast<float>(x0);
	const float weightY = y - static_cast<float>(y0);

	// Calculate dot product of distance and gradient vectors at the four corners
	const float dot00 = dot_grid_gradient(x0, y0, x, y);
	const float dot10 = dot_grid_gradient(x1, y0, x, y);
	const float dot01 = dot_grid_gradient(x0, y1, x, y);
	const float dot11 = dot_grid_gradient(x1, y1, x, y);

	// Interpolate along x-axis
	const float interpX0 = interpolate(dot00, dot10, weightX);
	const float interpX1 = interpolate(dot01, dot11, weightX);

	// Interpolate along y-axis and return the final value
	return interpolate(interpX0, interpX1, weightY);
}