#include "Game.h"
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "Math/AABB.h"
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

	for (int i = 0; i < MAX_ACTORS; ++i)
	{
		if (actors[i] == nullptr)
		{
			continue;
		}

		if (actors[i]->get_is_destroyed())
		{
			delete actors[i];
			actors[i] = nullptr;
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

void Game:: spawn_actor(Actor* actor)
{
	for (int i = 0; i < MAX_ACTORS; ++i)
	{
		if (actors[i] == nullptr)
		{
			actors[i] = actor;
			break;
		}
	}
}

Actor* Game::get_collision_actor(Actor* other, Collision_Channel channel)
{
	for (int i = 0; i < MAX_ACTORS; ++i)
	{
		if (actors[i] == other)
		{
			continue;
		}

		if (actors[i] == nullptr)
		{
			continue;
		}
		if (actors[i]->collision_channel != channel)
		{
			continue;
		}

		AABB a = AABB::from_position_size(other->position, other->size);
		AABB b = AABB::from_position_size(actors[i]->position, actors[i]->size);

		if (aabb_overlap(a, b))
		{
			return actors[i];
		}

	}
	return nullptr;
}
