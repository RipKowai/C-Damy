#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "Bullet.h"

Player :: Player(Vector position) 
	: Actor(position, Vector(32), COLOR_WHITE)
{
	collision_channel = Collision_Channel::Player;
}

Actor* player = new Player(Vector(50.f, 50.f));

void Player:: update()
{
	Vector input;

	if (engKeyDown(Key::W))
	{
		input.y -= 1.f;
	}
	if (engKeyDown(Key::S))
	{
		input.y += 1.f;
	}
	if (engKeyDown(Key::D))
	{
		input.x += 1.f;
	}
	if (engKeyDown(Key::A))
	{
		input.x -= 1.f;
	}

	input.normalize();
	position.x += input.x * speed * engDeltaTime();
	position.y += input.y * speed * engDeltaTime();

	if (engKeyPressed(Key::E))
	{
		speed += 50.f;
	}
	if (engKeyPressed(Key::Q))
	{
		speed -= 50.f;
	}

	if (engMouseButtonPressed(Mouse_Button::Left)) 
	{
		Vector bullet_direction = Vector(engMouseX(), engMouseY()) - position;
		bullet_direction.normalize();

		game.spawn_actor(new Bullet(position, bullet_direction));
	}
}

void Player::draw() 
{
	Vector aim_direction = Vector(engMouseX(), engMouseY()) - position;
	aim_direction.normalize();

	Vector crosshair_start = position + aim_direction * 50.f;
	Vector crosshair_end = position + aim_direction * 5000.f;

	engSetDrawColor(COLOR_RED);
	engDrawLine(crosshair_start.x, crosshair_start.y, 
		crosshair_end.x, crosshair_end.y);

	Actor::draw();
}

//-> Player::Player(Vector(50.f, 50.f))
// -> Actor:: ACtor(Vector(50.f, 50.f), Vector(32), COLOR_WHITE)