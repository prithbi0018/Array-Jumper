#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelView.h"


namespace Level
{
	LevelController::LevelController()
	{
		level_model = new LevelModel();
		level_view = new LevelView(this);
	}
	BoxDimensions LevelController::getBoxDimensions()
	{
		return level_view->getBoxDimensions();
	}

	LevelController::~LevelController()
	{
		destroy();
	}

	void LevelController::initialize()
	{
		level_view->initialize();
	}

	void LevelController::update()
	{
		level_view->update();
	}

	void LevelController::render()
	{
		level_view->render();
	}

	void LevelController::destroy()
	{
		delete(level_model);
		delete(level_view);
	}
	BlockType LevelController::getCurrentBoxValue(int currentPosition)
	{
		return level_model->getCurrentBoxValue(currentPosition);

	}

}	