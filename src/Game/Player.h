#pragma once
#include "Actor.h"
#include "TimerSystem.h"

class Player : public Actor
{
public:
	Player(Vector position);

	void update() override;
	void draw() override;

	void hit(int damage) override
	{
		if (is_invincible())
			return;

		last_hit_time = engCurrentTime();

		health -= damage;
		if (health <= 0)
		{
			destroy();
		}
	}

	float speed = 300.f;

private:
	static constexpr float INVINCIBILITY_TIME = 2.f;
	static constexpr int MAX_HEALTH = 3;
	static constexpr int M_ammo = 40.f;

	bool is_invincible()
	{
		return engTimePassedSince(last_hit_time) < INVINCIBILITY_TIME;
	}

	bool is_shooting = false;

	int health = MAX_HEALTH;
	int ammo = M_ammo;
	float last_hit_time = -INVINCIBILITY_TIME;

	Timer_System s_timers;
};
