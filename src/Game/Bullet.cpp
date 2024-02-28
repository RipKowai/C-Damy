#include "Bullet.h"
#include "Game.h"
#include "Actor.h"

Bullet::Bullet(Vector position, Vector direction)
	: Actor(position, Vector(4.f), COLOR_YELLOW), direction(direction)
{
	this->direction.normalize();
}

void Bullet::update()
{
	position += direction * 1000.f * engDeltaTime();
	Actor* hit_actor = game.get_collision_actor(this, Collision_Channel::Enemy);
	if (hit_actor != nullptr)
	{
		hit_actor->destroy();
		destroy();
	}
}