#pragma once

#include "Engine/GameEngine.h"

class SpaceDebris : public GameObject
{
public:
	//creates our SpaceDebris
	SpaceDebris(sf::Vector2f pos);

	// Functions overriden from GameOblect:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);
private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<SpaceDebris> SpaceDebrisPtr;