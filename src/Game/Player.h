#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	Player(Vector position);

	void update() override;
	void draw();
	float speed = 500.f;
};

