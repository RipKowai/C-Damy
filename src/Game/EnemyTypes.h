#pragma once
#include "Enemy.h"

class NormalEnemy : public Enemy
{
public:
	NormalEnemy(Vector position) : Enemy(position)
	{
		init(20.f, COLOR_RED);

		speed = 50.f;
		MAX_HEALTH = 100.f;
		health = MAX_HEALTH;
	}
};

class Tank : public Enemy
{
public:
	Tank(Vector position) : Enemy(position)
	{
		init(50.f, COLOR_GRAY);

		speed = 25.f;
		MAX_HEALTH = 500.f;
		health = MAX_HEALTH;
	}
};