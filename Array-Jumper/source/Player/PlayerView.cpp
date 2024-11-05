#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

namespace Player
{
    using namespace Global;
    using namespace UI::UIElement;

    PlayerView::PlayerView(PlayerController* controller)
    {
        player_image = new ImageView();
        game_window = nullptr;
        player_height = 0.0f;
        player_width = 0.0f;
    }

    PlayerView::~PlayerView()
    {
        delete player_image; // Clean up the player image
    }

    void PlayerView::initialize()
    {
        game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        loadPlayer();
    }

    void PlayerView::update()
    {
        updatePlayerPosition();
    }

    void PlayerView::render()
    {
        drawPlayer();
    }

    void PlayerView::loadPlayer()
    {
        calculatePlayerDimensions();
        initializePlayerImage();
    }

    void PlayerView::calculatePlayerDimensions()
    {
        player_width = 1000.f;
        player_height = 1000.f;
    }

    void PlayerView::updatePlayerPosition()
    {
        // Update player position logic here
    }

    sf::Vector2f PlayerView::calculatePlayerPosition()
    {
        return sf::Vector2f(0, 0);
    }

    void PlayerView::initializePlayerImage()
    {
        player_image->initialize(Config::character_texture_path, player_width, player_height, sf::Vector2f(0, 0));
    }

    void PlayerView::drawPlayer()
    {
        player_image->render();
    }
}