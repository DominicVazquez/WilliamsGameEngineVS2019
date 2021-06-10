#include "SpaceDebris.h"
#include "Explosion.h"
#include "GameScene.h"

const float SPEED = 0.25f;

SpaceDebris::SpaceDebris(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/SpaceDebris.png"));
	sprite_.setPosition(pos);
	assignTag("SpaceDebris");
	setCollisionCheckEnabled(true);
}

void SpaceDebris::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void SpaceDebris::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();

		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

sf::FloatRect SpaceDebris::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

void SpaceDebris::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		otherGameObject.makeDead();

		sf::Vector2f pos = sprite_.getPosition();
		float x = pos.x;
		float y = pos.y;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float ExplosionX = x + bounds.width;
		float ExplosionY = y + (bounds.height / 2.0f);

		ExplosionPtr explosion = std::make_shared<Explosion>(sf::Vector2f(ExplosionX, ExplosionY));
		GAME.getCurrentScene().addGameObject(explosion);

		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseScore();
		scene.increaseScore();
		scene.increaseScore();
		scene.increaseScore();
		scene.increaseScore();
		scene.increaselives();

	}

	makeDead();
}