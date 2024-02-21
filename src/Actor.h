#pragma once
#include "Math/Vector.h"
#include "Engine/TinyEngine.h"
class Actor
{
public:
	Actor() { }
	Actor(Vector position, Vector size, Color color)
		: position(position), size(size), color(color) {}

	void draw();

	Vector position;
	Vector size;
	Color color = COLOR_WHITE;
};