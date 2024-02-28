#include "Player.h"
#include "Game.h"
#include "Enemy.h"
#include "Bullet.h"

Player::Player(Vector position)
	: Actor(position, Vector(32), COLOR_WHITE)
{
	collision_channel = Collision_Channel::Player;
}

void Player::update()
{
	Vector input;

	if (engKeyDown(Key::W))
		input.y -= 1.f;
	if (engKeyDown(Key::S))
		input.y += 1.f;
	if (engKeyDown(Key::D))
		input.x += 1.f;
	if (engKeyDown(Key::A))
		input.x -= 1.f;

	input.normalize();
	position += input * speed * engDeltaTime();

	if (engKeyPressed(Key::E))
		speed += 50.f;
	if (engKeyPressed(Key::Q))
		speed -= 50.f;

	if (engMouseButtonPressed(Mouse_Button::Left))
	{
		Vector mouse_position = Vector(engMouseX(), engMouseY());
		mouse_position = game->get_camera().screen_to_world(mouse_position);

		Vector bullet_direction = mouse_position - position;
		bullet_direction.normalize();

		game->spawn_actor(new Bullet(position, bullet_direction));
	}
}

void Player::draw()
{
	Vector mouse_position = Vector(engMouseX(), engMouseY());
	mouse_position = game->get_camera().screen_to_world(mouse_position);

	Vector aim_direction = mouse_position - position;
	aim_direction.normalize();

	Vector crosshair_start = game->get_camera().world_to_screen(position + aim_direction * 45.f);
	Vector crosshair_end = game->get_camera().world_to_screen(position + aim_direction * 5000.f);

	engSetDrawColor(COLOR_RED);
	engDrawLine(
		crosshair_start.x, crosshair_start.y,
		crosshair_end.x, crosshair_end.y);

	Actor::draw();
}
