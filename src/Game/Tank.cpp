#include "Tank.h"
#include "Game.h"
#include "Engine//TinyEngine.h"

int Tank::am_tanks = 0;

Tank::Tank(Vector position)
	: Actor(position, Vector(50.f, 50.f), COLOR_DARK_GRAY)
{
	collision_channel = Collision_Channel::Enemy;
	am_tanks++;
}

Tank::~Tank()
{
	am_tanks--;
}

void Tank::update()
{
	if (game ->get_player() != nullptr)
	{
		Vector direction = game->get_player()->position - position;
		direction.normalize();

		position += direction * t_speed * engDeltaTime();

		Actor* player = game->get_colliding_actor(this, Collision_Channel::Player);
		if (player)
		{
			player->hit(2);
		}
	}
}

void Tank::draw()
{
	if (t_health < M_health)
	{
		float health_percentage = float(t_health) / M_health;
		Vector screen_position = game->get_camera().world_to_screen(position);

		engSetDrawColor(0x000000AA);
		engFillRect(screen_position.x - 26.f, screen_position.y - 30.f, 26.f * 2.f, 8.f);

		engSetDrawColor(COLOR_RED);
		engFillRect(
			screen_position.x - 26.f,
			screen_position.y - 30.f,
			26.f * 2.f * health_percentage,
			8.f
		);
	}

	Actor:draw();
}