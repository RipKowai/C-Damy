#include "Player.h"
#include "PlayerInput.h"

void Player::update()
{
	update_input(position, speed);
}