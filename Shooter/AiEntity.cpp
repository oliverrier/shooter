#include "AiEntity.h"


CAiEntity::CAiEntity(const char* name, sf::Sprite sprite):CEntity(name, sprite)
{
	sf::Vector2f startPosition;
	startPosition.y = (float)getRandomInt(80, 1000);
	startPosition.x = 2000;
	Sprite.setPosition(startPosition);
	Sprite.setScale(0.5f, 0.5f);

	Destination.x = (float)getRandomInt(960, 1900);
	Destination.y = (float)getRandomInt(20, 1000);
}

const sf::Vector2f& CAiEntity::GetDestination()
{
	return Destination;
}

void CAiEntity::SetDestination(sf::Vector2f newDestination)
{
	Destination = newDestination;
}
