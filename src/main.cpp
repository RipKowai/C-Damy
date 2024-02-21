#include "Engine/TinyEngine.h"
#include "PlayerInput.h"
#include "Math/Vector.h"

class Actor 
{
public:
	Actor() { }
	Actor(Vector position, Vector size, Color color) 
		: position(position), size(size), color(color){}
	Vector position;
	Vector size;
	Color color = COLOR_WHITE;
};

void update_input(Vector& position, float& speed);
void draw_actor(Actor actor);

//macro
#define NUM_ACTORS 10
int main()
{
	engInit("Tiny Engine", 1480, 800);
	// This here is the Player Spawn Position that is being randomized
	float  speed = 100.f;

	//this here is a 
	Actor actors[NUM_ACTORS];
	for (int i = 0; i < NUM_ACTORS; ++i)
	{
		actors[i] = Actor(Vector(engRandom(1400), engRandom(800)), Vector(16.f), COLOR_SALMON);
	}

	Actor* player = &actors[0];
	(*player) = Actor(Vector(400.f, 300.f), Vector(32.f), COLOR_GREEN);

	while(engBeginFrame()) 
	{
		engSetDrawColor(COLOR_DARK_GRAY);
		engClearScreen();

		engFillRect(position.x, position.y, 32, 32);


		update_input(player->position, speed);
		//draw_actor(player);

		for (int i = 0; i < NUM_ACTORS; ++i)
		{
			draw_actor(actors[i]);
		}
	}
}

void draw_actor(Actor actor) 
{
	engSetDrawColor(actor.color);
	engFillRect(
		(int)actor.position.x,
		(int)actor.position.y,
		(int)actor.size.x,
		(int)actor.size.y
	);
}