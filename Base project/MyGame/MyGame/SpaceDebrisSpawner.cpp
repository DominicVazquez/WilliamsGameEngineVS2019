#include"SpaceDebrisSpawner.h"

//The number of milliseconds between meteor spawns.
const int SPAWN_DELAY = 10000;

void SpaceDebrisSpawner::update(sf::Time& elapsed)
{
	//Determine how much time has passed and adjust our timer
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;

	//if our timer has elapsed, reset it and spawn a SpaceDebris.
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;

		sf::Vector2u size = GAME.getRenderWindow().getSize();

		//spawn the meteor off the righ side of the screen.
		//We're assuming the SpaceDebris ins't more than 100 pixels wide.
		float SpaceDebrisX = (float)(size.x + 100);

		//Spawn the SpaceDebris somewhere along the height of window, randomly.
		float SpaceDebrisY = (float)(rand() % size.y);

		//create a SpaceDebris and add it to the scene
		SpaceDebrisPtr spaceDebris = std::make_shared<SpaceDebris>(sf::Vector2f(SpaceDebrisX, SpaceDebrisY));
		GAME.getCurrentScene().addGameObject(spaceDebris);
	}
}
