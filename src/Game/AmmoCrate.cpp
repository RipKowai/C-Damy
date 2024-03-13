#include "AmmoCrate.h"

AmmoCrate::AmmoCrate(Vector position)
	: Actor(position, Vector(20), COLOR_YELLOW)
{
	collision_channel = Collision_Channel::AmmoCrate;
}