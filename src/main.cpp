#include "Engine/TinyEngine.h"
#include "PlayerInput.h"
#include "Math/Vector.h"
#include "Actor.h"
#include "Game/Game.h"



void update_input(Vector& position, float& speed);
void draw_actor(Actor actor);

//macro
#define NUM_ACTORS 10

int main()
{
	engInit("Tiny Engine", 1480, 800);

	while(engBeginFrame()) 
	{
		engSetDrawColor(COLOR_DARK_GRAY);
		engClearScreen();

		if (engKeyPressed(Key::Escape))
		{
			return 0;
		}

		game.update();
		game.render();

		
	}
}