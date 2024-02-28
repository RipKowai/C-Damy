#include "Camera.h"
#include "Actor.h"
#include "Game.h"
#include "Config/Config.h"

void Camera::update()
{
	if (game->get_player() != nullptr)
	{
		position = game->get_player() -> position;
	}
}

Vector Camera::world_to_screen(Vector vec)
{
	using namespace Config;
	return vec - position + Vector(WINDOW_WIDTH /2, WINDOW_HEIGHT / 2);
}

Vector Camera::screen_to_world(Vector vec)
{
	using namespace Config;
	return vec + position - Vector(WINDOW_WIDTH /2, WINDOW_HEIGHT/ 2);
}
