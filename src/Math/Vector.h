#pragma once

struct Vector
{
	Vector() {}
	Vector(float scalar)
		: x(scalar), y(scalar) {}
	Vector(float x, float y)
		: x(x), y(y) {}
	float x = 0;
	float y = 0;
};