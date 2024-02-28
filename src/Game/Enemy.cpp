#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(Vector position)
	: Actor(position, Vector(20.f, 20.f), COLOR_RED)
{
	collision_channel = Collision_Channel::Enemy;
}

void Enemy::update()
{
	if (game.get_player() != nullptr)
	{
		Vector direction = game.get_player()->position - position;
		direction.normalize();

		position += direction * speed * engDeltaTime();

		Actor* player = game.get_collision_actor(this, Collision_Channel::Player);
		if (player)
		{
			player->destroy();
		}
	}
}