#include"Actor.h"

void Actor::draw() 
{
	engSetDrawColor(color);
	engFillRect(
		(int)position.x,
		(int)position.y,
		(int)size.x,
		(int)size.y
	);
}