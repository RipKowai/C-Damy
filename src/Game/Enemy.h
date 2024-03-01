#pragma once
#include "Actor.h"

class Enemy : public Actor
{
public:
	static int NUM_ENEMIES;

	Enemy(Vector position);
	~Enemy();
	void update() override;
	void draw() override;

	float speed = 50.f;

	void hit(int damage) override
	{
		health -= damage;
		if (health <= 0)
			destroy();
	}

private:
	static constexpr int MAX_HEALTH = 100;
	int health = MAX_HEALTH;
};
