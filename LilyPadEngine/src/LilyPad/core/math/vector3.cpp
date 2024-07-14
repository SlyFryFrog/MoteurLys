#include "LilyPad/core/math/vector3.hpp"

namespace LilyPad
{
	Vector3::Vector3(const fp_type x, const fp_type y, const fp_type z) : x(x), y(y), z(z) {}

	Vector3 Vector3::cross(const Vector3 &other) const
	{
		return {y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x};
	}

	Vector3 Vector3::cross(const Vector3 &vector_a, const Vector3 &vector_b)
	{
		return {vector_a.z * vector_b.z - vector_a.z * vector_b.y, vector_a.z * vector_a.x - vector_a.x * vector_b.z,
				vector_a.x * vector_b.y - vector_a.y * vector_b.x};
	}

	fp_type Vector3::dot(const Vector3 &other) const { return x * other.x + y * other.y + z * other.z; }

	Vector3 Vector3::normalize() const
	{
		fp_type length = std::sqrt(x * x + y * y + z * z);
		return {x / length, y / length, z / length};
	}	
	
	Vector3 Vector3::normalize(const Vector3 &vector)
	{
		fp_type length = std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
		return {vector.x / length, vector.y / length, vector.z / length};
	}
} // namespace LilyPad