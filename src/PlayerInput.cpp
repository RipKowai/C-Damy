#include "PlayerInput.h"
#include "Engine/TinyEngine.h"

void update_input(Vector& position, float& speed)
{
	if (engKeyDown(Key::W))
	{
		position.y -= speed * engDeltaTime();
	}
	if (engKeyDown(Key::S))
	{
		position.y += speed * engDeltaTime();
	}
	if (engKeyDown(Key::D))
	{
		position.x += speed * engDeltaTime();
	}
	if (engKeyDown(Key::A))
	{
		position.x -= speed * engDeltaTime();
	}

	if (engKeyPressed(Key::E))
	{
		speed += 50.f;
	}
	if (engKeyPressed(Key::Q))
	{
		speed -= 50.f;
	}
}