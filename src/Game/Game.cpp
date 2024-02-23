#include "Game.h"
#include "Actor.h"
#include "PlayerInput.h"
#include "Player.h"

Game game;

Game::Game()
{
	actors[0] = new Player();
	player = actors[0];
}

void Game::update()
{
	for (int i = 0; i < MAX_ACTORS; ++i)
	{
		if (actors[i] != nullptr)
		{
			actors[i]->update();
		}
	}
}

void Game::render() 
{
	for (int i = 0; i < MAX_ACTORS; ++i)
	{
		if (actors[i] != nullptr)
		{
			actors[i]->draw();
		}
	}
}