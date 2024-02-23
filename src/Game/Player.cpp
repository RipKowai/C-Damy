#include "Player.h"
#include "PlayerInput.h"

Player :: Player(Vector position) 
	: Actor(position, Vector(32), COLOR_WHITE)
{

}

void Player::update()
{
	update_input(position, speed);
}

Actor* player = new Player(Vector(50.f, 50.f));

//-> Player::Player(Vector(50.f, 50.f))
// -> Actor:: ACtor(Vector(50.f, 50.f), Vector(32), COLOR_WHITE)