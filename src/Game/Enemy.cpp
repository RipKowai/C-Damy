#include "Enemy.h"
#include "Game.h"
Enemy::Enemy(Vector position)
	: Actor(position, Vector(20.f, 20.f), COLOR_RED)
{

}
void Enemy::update()
{
	Vector direction = game.get_player()->position - position;
	direction.normalize();

	position += direction * speed * engDeltaTime();
}