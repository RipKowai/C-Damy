#pragma once
#define MAX_ACTORS 20

//forward-declare
class Actor;



class Game
{
	public:
		Game();
		
		void update();
		void render();

		Actor* get_player() { return player; }

	private:
		Actor* actors[MAX_ACTORS] = { nullptr };
		Actor* player = nullptr;

		float player_speed = 100.f;
};

extern Game game;
