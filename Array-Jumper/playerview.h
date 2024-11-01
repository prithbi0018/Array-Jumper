#pragma once
#include "../../header/UI/UIElement/ImageView.h"

namespace Player
{
    using namespace UI::UIElement;

    class PlayerController;

    class PlayerView
    {
    private:
        ImageView* player_image;
        sf::RenderWindow* game_window;
        PlayerController* player_controller;		

        float player_height;
        float player_width;

        void initializePlayerImage();
        void drawPlayer();
        void loadPlayer();
        void calculatePlayerDimensions();
        void updatePlayerPosition();
        sf::Vector2f calculatePlayerPosition();

    public:
       
        PlayerView() : player_controller(nullptr), game_window(nullptr), player_image(new ImageView()) {}

        PlayerView(PlayerController* controller) : player_controller(controller), game_window(nullptr), player_image(new ImageView()) {}

        ~PlayerView();

        void initialize();
        void update();
        void render();
    };
}