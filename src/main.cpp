#include "Engine/TinyEngine.h"


struct Vector 
{
	Vector() {}
	Vector(float scalar)
		: x(scalar), y(scalar){}
	Vector(float x, float y)
		: x(x), y(y) {}
	float x = 0;
	float y = 0;
};

class Actor 
{
public:
	Actor(Vector position, Vector size, Color color) 
		: position(position), size(size), color(color){}
	Vector position;
	Vector size;
	Color color;
};

void update_input(Vector& position, float& speed);
void draw_actor(Actor actor);

int main()
{
	Actor player = Actor(Vector(50.f, 50.f), Vector(32.f), COLOR_WHITE);
	float  speed = 100.f;
	char mySpeed[] = "Hello";

	engInit("Tiny Engine", 1480, 800);

	Vector position = Vector(100.f, 100.f);

	while(engBeginFrame()) 
	{
		engSetDrawColor(COLOR_DARK_GRAY);
		engClearScreen();

		engSetDrawColor(COLOR_VIOLET);
		engFillRect(position.x, position.y, 32, 32);
		engDrawTextF(10, 10, "Speed: %f", speed);	

		engDrawTextF(1000, 10, "Speed: %f", speed);
		update_input(player.position, speed);
		draw_actor(player);
	}
}

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