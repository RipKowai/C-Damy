#pragma once
#include "Actor.h"

class Enemy : public Actor
{
public:
	Enemy(Vector position);
	void update() override;

	float speed = 50.f;
};
