#pragma once
#include "Vector.h"

struct AABB
{
public:
	static AABB from_position_size(Vector position, Vector size);

	AABB() {}
	AABB(Vector min, Vector max): min(min), max(max) {}

	Vector min;
	Vector max;
};

bool aabb_overlap(AABB a, AABB b);

