#pragma once

#include "../Event/EventService.h"
<<<<<<< HEAD
#include "../Level/BlockType.h"
=======
=======


>>>>>>> 737d5aff4ae649e3d2ade538e822d3ff503d12ef

namespace Player
{
	class PlayerView;
	class PlayerModel;
	enum class PlayerState;

	enum MovementDirection;


	class PlayerController
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;

		Event::EventService* event_service;

		void move(MovementDirection direction);
		void jump(MovementDirection direction);
		bool isPositionInBound(int targetPosition);
		Level::BlockType getCurrentBoxValue(int currentPosition);
		void readInput();
=======

		void destroy();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		int getCurrentPosition();
	};
}
