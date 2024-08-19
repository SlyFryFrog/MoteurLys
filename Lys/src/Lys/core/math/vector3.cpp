#include "Lys/core/math/vector3.hpp"

namespace Lys
{
	Vector3::Vector3(const fp_type x, const fp_type y, const fp_type z) : x(x), y(y), z(z) {}

	Vector3 Vector3::cross(const Vector3 &other) const
	{
		return {y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x};
	}

	Vector3 Vector3::cross(const Vector3 &vector_a, const Vector3 &vector_b)
	{
		return {vector_a.y * vector_b.z - vector_a.z * vector_b.y, vector_a.z * vector_b.x - vector_a.x * vector_b.z,
				vector_a.x * vector_b.y - vector_a.y * vector_b.x};
	}

	fp_type Vector3::dot(const Vector3 &other) const { return x * other.x + y * other.y + z * other.z; }

	Vector3 Vector3::normalize() const
	{
		fp_type length = std::sqrt(x * x + y * y + z * z);
		if (length == 0)
			return {0, 0, 0}; // Handle zero length to avoid division by zero
		return {x / length, y / length, z / length};
	}

	Vector3 Vector3::normalize(const Vector3 &p_vector)
	{
		return p_vector.normalize();
	}
} // namespace Lys