#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"	

namespace Player
{
    using namespace Global;
    using namespace UI::UIElement;

    PlayerView::~PlayerView() {
        delete player_image; e
    }

    void PlayerView::initialize() {
        game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        loadPlayer();
    }

    void PlayerView::update() {
     
    }

    void PlayerView::render() {
        if (player_controller && player_controller->getPlayerState() == PlayerState::ALIVE) {
            drawPlayer();
        }
    }

    void PlayerView::loadPlayer() {
        calculatePlayerDimensions();
        initializePlayerImage();
    }

    void PlayerView::calculatePlayerDimensions() {
        player_width = 1000.f;
        player_height = 1000.f;
    }

    void PlayerView::updatePlayerPosition() {
        
    }

    sf::Vector2f PlayerView::calculatePlayerPosition() {
        return sf::Vector2f(0, 0);
    }

    void PlayerView::initializePlayerImage() {
        player_image->initialize(Config::character_texture_path, player_width, player_height, sf::Vector2f(0, 0));
    }

    void PlayerView::drawPlayer() {
        player_image->render();
    }
}