#pragma once

namespace Gameplay
{
	class GameplayController;

	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();
		void startGame();
		void onPositionChanged(int position);
		void onDeath();
	};
}
