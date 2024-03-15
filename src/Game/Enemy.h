#pragma once
#include "Actor.h"

class Enemy : public Actor
{
public:
	static int NUM_ENEMIES;

	Enemy(Vector position);
	~Enemy() override;
	void update() override;
	void draw() override;

	void init(Vector a_size, Color a_color);

	void hit(int damage) override
	{
		health -= damage;
		if (health <= 0)
		{
			destroy();
		}
	}

	float speed = 50.f;

	int MAX_HEALTH = 100;
	int health;
};

extern int NUM_ENEMIES;
