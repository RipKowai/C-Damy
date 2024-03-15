#pragma once
#include "PickUp.h"

class HealthPotion : public PickUp
{
public:
	HealthPotion(Vector position)  : PickUp(position)
	{
		init(20, COLOR_GREEN);
		collision_channel = Collision_Channel::PickUp;
	}
};

class AmmoCrate : public PickUp
{
public:
	AmmoCrate(Vector position) : PickUp(position)
	{
		init(20, COLOR_YELLOW);
		collision_channel = Collision_Channel::AmmoCrate;
	}
};