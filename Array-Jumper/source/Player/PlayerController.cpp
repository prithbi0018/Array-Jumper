#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"

#include "../../header/Player/MovementDirection.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"

namespace Player
{
	using namespace Level;
	using namespace Global;
	using namespace Sound;



namespace Player
{

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
	}

	PlayerController::~PlayerController()
	{
		destroy();
	}

	void PlayerController::initialize()
	{

		event_service = ServiceLocator::getInstance()->getEventService();


		player_model->initialize();
		player_view->initialize();
	}

	void PlayerController::update()
	{
		player_view->update();

		readInput();	


	}

	void PlayerController::render()
	{
		player_view->render();
	}
	void PlayerController::move(MovementDirection direction)
	{
		int steps, targetPosition;
		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = 1;
			break;
		case MovementDirection::BACKWARD:
			steps = -1;
			break;
		default:
			steps = 0;
			break;
		}
		targetPosition = player_model->getCurrentPosition() + steps;
		if (!isPositionInBound(targetPosition))
		{
			return;
		}
		player_model->setCurrentPosition(targetPosition);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::MOVE);
		ServiceLocator::getInstance()->getGameplayService()->onPositionChanged(targetPosition);

	}
	bool PlayerController::isPositionInBound(int targetPosition)
	{
		if (targetPosition >= 0 && targetPosition < LevelData::number_of_boxes)
		{
			return true;
		}
		return false;
	}
	void PlayerController::readInput()
	{
		if (event_service->pressedRightArrowKey() || event_service->pressedDKey())
		{
			if (event_service->heldSpaceKey())
				jump(MovementDirection::FORWARD);
			else
				move(MovementDirection::FORWARD);
		}
		if (event_service->pressedLeftArrowKey() || event_service->pressedAKey())
		{
			if (event_service->heldSpaceKey())
				jump(MovementDirection::BACKWARD);
			else
				move(MovementDirection::BACKWARD);;
		}
	}


	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}

	void PlayerController::setPlayerState(PlayerState new_player_state)
	{
		player_model->setPlayerState(new_player_state);
	}

	void PlayerController::destroy()
	{
		delete(player_model);
		delete(player_view);
	}
	int PlayerController::getCurrentPosition()
	{
		return player_model->getCurrentPosition();
	}
	BlockType PlayerController::getCurrentBoxValue(int currentPosition)
	{
		return ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(currentPosition);
	}
	void PlayerController::jump(MovementDirection direction)
	{
		int current_position = player_model->getCurrentPosition();
		BlockType box_value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(current_position);
		int steps, targetPosition;
		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = box_value;
			break;
		case MovementDirection::BACKWARD:
			steps = -box_value;
			break;
		default:
			steps = 0;
			break;
		}
		targetPosition = current_position + steps;
		if (!isPositionInBound(targetPosition))
			return;
		player_model->setCurrentPosition(targetPosition);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::JUMP);
		ServiceLocator::getInstance()->getGameplayService()->onPositionChanged(targetPosition);
	}
	void PlayerController::takeDamage()
	{
		resetPlayer();
	}
	void PlayerController::resetPlayer()
	{
		player_model->resetPlayer();

	}




}