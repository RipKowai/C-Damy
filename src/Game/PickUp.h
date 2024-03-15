#pragma once
#include "Actor.h"

class PickUp : public Actor
{
public:
	PickUp(Vector position);

	void init(Vector a_size, Color a_color);
};
