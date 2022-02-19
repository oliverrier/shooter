#include "AiEntity.h"


CAiEntity::CAiEntity(const char* name, sf::Sprite sprite, CLevel& currentLevel) :CPlayerEntity(name, sprite, currentLevel), MaxDelayToShootAgain((float)getRandomInt(1,5))
{
	MaxLife = 5;
	CurrentLife = 5;

	sf::Vector2f startPosition;
	startPosition.y = (float)getRandomInt(80, 1000);
	startPosition.x = 2000;

	const sf::FloatRect globalBounds = Sprite.getGlobalBounds();
	Sprite.setOrigin(globalBounds.width / 2, globalBounds.height / 2);

	Sprite.setPosition(startPosition);
	Sprite.setScale(0.25f, 0.25f);


	Destination = startPosition;
}

CAiEntity::~CAiEntity()
{
}

const sf::Vector2f& CAiEntity::GetDestination()
{
	return Destination;
}

void CAiEntity::SetDestination(sf::Vector2f newDestination)
{
	Destination = newDestination;
}

void CAiEntity::SetRandomDestination(sf::RenderWindow& Window)
{
	const sf::FloatRect globalBounds = Sprite.getGlobalBounds();
	const sf::FloatRect viewport = (sf::FloatRect)Window.getViewport(Window.getView());

	Destination.x = (float)getRandomInt((int)globalBounds.width, (int)(viewport.width - globalBounds.width));
	Destination.y = (float)getRandomInt((int)globalBounds.height, (int)(viewport.height - globalBounds.height));
}

bool& CAiEntity::GetCanShoot()
{
	return CanShoot;
}

void CAiEntity::SetCanShoot(bool canShoot)
{
	CanShoot = canShoot;
}

const float& CAiEntity::GetDelayToShootAgain()
{
	return DelayToShootAgain;
}

void CAiEntity::SetDelayToShootAgain(float delayToShootAgain)
{
	DelayToShootAgain = delayToShootAgain;
}

const float& CAiEntity::GetMaxDelayToShootAgain() {
	return MaxDelayToShootAgain;
};
void CAiEntity::SetMaxDelayToShootAgain(float maxDelayToShootAgain) {
	MaxDelayToShootAgain = maxDelayToShootAgain;
};