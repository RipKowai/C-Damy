#include "PickUp.h"

PickUp::PickUp(Vector position)
	: Actor(position, Vector(20), COLOR_GREEN)
{
	collision_channel = Collision_Channel::PickUp;
}

void PickUp::init(Vector a_size, Color a_color)
{
	size = a_size;
	color = a_color;
}
