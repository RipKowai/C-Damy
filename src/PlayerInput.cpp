#include "PlayerInput.h"
#include "Engine/TinyEngine.h"

void update_input(Vector& position, float& speed)
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
}