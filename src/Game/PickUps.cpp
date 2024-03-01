#include "PickUps.h"

PickUps :: PickUps(Vector position)
	: Actor(position, Vector(20), COLOR_GREEN)
{
	collision_channel = Collision_Channel::PickUps;
}