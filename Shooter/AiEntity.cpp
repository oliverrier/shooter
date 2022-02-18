#include "AiEntity.h"

CAiEntity::CAiEntity(const char* name, sf::Sprite sprite):CEntity(name, sprite)
{
	sf::Vector2f startPosition;
	startPosition.y = getRandomInt(80, 1000);
	startPosition.x = 500;
	Sprite.setPosition(startPosition);
	Sprite.setScale(0.5f, 0.5f);

	Destination.x = getRandomInt(960, 1900);
	Destination.y = getRandomInt(20, 1000);
}

const sf::Vector2f& CAiEntity::GetDestination()
{
	return Destination;
}

void CAiEntity::SetDestination(sf::Vector2f newDestination)
{
	Destination = newDestination;
}
