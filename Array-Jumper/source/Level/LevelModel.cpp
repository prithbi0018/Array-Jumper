#include "../../header/Level/LevelModel.h"

namespace Level
{
	LevelModel::LevelModel()
	{

	}

	LevelModel::~LevelModel()
	{

	}

	void LevelModel::initialize()
	{

	}

	void LevelModel::update()
	{

	}
	BlockType LevelModel::getCurrentBoxValue(int currentPosition)
	{
		return current_level_data.level_boxes[currentPosition];
	}

}