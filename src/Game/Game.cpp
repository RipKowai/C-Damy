#include "Game.h"
#include "Actor.h"
#include "PlayerInput.h"
#include "Player.h"
#include "Enemy.h"

Game game;

Game::Game()
{
	actors[0] = new Player(Vector(100.f, 100.f));
	player = actors[0];

	actors[1] = new Enemy(Vector(600.f, 370.f));
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