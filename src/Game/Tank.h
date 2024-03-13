#pragma once
#include "Actor.h"	

class Tank  : public Actor
{
public:
	static int am_tanks;

	Tank(Vector position);
	~Tank() override;

	void update() override;
	void draw() override;

	void hit(int damage) override
	{
		t_health -= damage;
		if (t_health <= 0)
		{
			destroy();
		}
	}

	float t_speed = 25.f;

private:
	static constexpr int M_health = 200;
	int t_health = M_health;
};

extern int am_tanks;

