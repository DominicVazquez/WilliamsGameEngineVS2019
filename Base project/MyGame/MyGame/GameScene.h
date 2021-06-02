#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene
{
 public:
		// Creates our Scene.
		GameScene();

		// get the current score
		int getScore();

		// increase the score
		void increaseScore();

		//get the number of lives
		int getlives();

		//Decrease the number of lives
		void decreasedlives();
private:
		int score_ = 0;
		int lives_ = 3;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
