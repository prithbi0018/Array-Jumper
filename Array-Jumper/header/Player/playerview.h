#pragma once
#include "../../header/UI/UIElement/ImageView.h"

namespace Player
{
    using namespace UI::UIElement;

    class PlayerController; // Forward declaration

    class PlayerView
    {
    private:
        ImageView* player_image;
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
        PlayerView(PlayerController* controller); // Constructor with controller parameter
        ~PlayerView();

        void initialize();
        void update();
        void render();
    };
}