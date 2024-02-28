#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	Player(Vector position);

	void update() override;
	void draw() override;
	float speed = 300.f;
};
