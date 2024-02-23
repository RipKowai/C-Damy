#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	void update() override;
	float speed = 100.f;
};

