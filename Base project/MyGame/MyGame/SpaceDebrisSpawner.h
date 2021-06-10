#pragma once

#include "Engine/GameEngine.h"
#include "SpaceDebris.h"

class SpaceDebrisSpawner : public GameObject
{
public:
	void update(sf::Time& elapsed);
private:
	int timer_ = 0;
};

typedef std::shared_ptr<SpaceDebrisSpawner> SpaceDebrisSpawnerPtr;