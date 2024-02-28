#pragma once
#define MAX_ACTORS 20

//forward-declare
class Actor;
enum class Collision_Channel;


class Game
{
	public:
		Game();
		
		void update();
		void render();


		Actor* get_player() { return player; }

		void spawn_actor(Actor* actor);

		Actor* get_collision_actor(Actor* other, Collision_Channel channel);

	private:
		Actor* actors[MAX_ACTORS] = { nullptr };
		Actor* player = nullptr;

		float player_speed = 100.f;
};

extern Game game;
