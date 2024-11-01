#pragma once
#include "../../header/UI/UIElement/ImageView.h"

namespace Player
{
	using namespace UI::UIElement;

	class PlayerView
	{
	private:
		UI::UIElement::ImageView* player_image;
		sf::RenderWindow* game_window;

		float player_height;
		float player_width;

		void initializePlayerImage();
		void drawPlayer();
		void loadPlayer();
		void calculatePlayerDimensions();
		void updatePlayerPosition();
		sf::Vector2f calculatePlayerPosition();

	public:
		PlayerView()
		{
			game_window = nullptr;
			player_image = new ImageView();

		}
		~PlayerView();

		void initialize();
		void update();
		void render();
	};

}