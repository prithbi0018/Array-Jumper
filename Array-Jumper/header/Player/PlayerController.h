#pragma once
#include "../Event/EventService.h"

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
		bool isPositionInBound(int targetPosition);
		void readInput();
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
