#include "GameScene.h"
#include "ship.h"
#include "MeteorSpawner.h"
#include "Score.h"
#include "GameOverScene.h"
#include "SpaceDebrisSpawner.h"

GameScene::GameScene()
{
	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);

	SpaceDebrisSpawnerPtr spaceDebrisSpawner = std::make_shared<SpaceDebrisSpawner>();
	addGameObject(spaceDebrisSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);

}

int GameScene::getScore()
{
		return score_;
}

void GameScene::increaseScore()
{
		++score_;
}

int GameScene::getlives()
{
	return lives_;
}

void GameScene::decreasedlives()
{
	--lives_;

	if(lives_ == 0)
	{
			GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(score_);
			GAME.setScene(gameOverScene);
	}
}

void GameScene::increaselives()
{
	++lives_;
}