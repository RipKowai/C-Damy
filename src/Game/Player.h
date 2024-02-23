#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	Player(Vector position);

	void update() override;
	float speed = 100.f;
};

