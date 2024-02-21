#pragma once
#include <cmath>
struct Vector
{
	Vector() {}
	Vector(float scalar)
		: x(scalar), y(scalar) {}
	Vector(float x, float y)
		: x(x), y(y) {}

	void normalize()
	{
		float lengthSqrd = (x * x + y * y);
		if (lengthSqrd < 0.001f)
			return;

		float lenght = sqrtf(lengthSqrd);
		x = x / lenght;
		y = y / lenght;
	}
	Vector operator+(Vector other) { return Vector(x + other.x, y + other.y); }

	float x = 0;
	float y = 0;
};