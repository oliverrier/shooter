#include "AiController.h"
#include "AiEntity.h"
#include "Level.h"

CAiController::CAiController(sf::RenderWindow& window, float maxVelocity): CController(maxVelocity), Window{window}
{
}



void CAiController::UpdateDelayCanShoot(const float dt, CAiEntity& entity)
{
	entity.SetDelayToShootAgain(entity.GetDelayToShootAgain() + dt);
	if (entity.GetDelayToShootAgain() > entity.GetMaxDelayToShootAgain()) {
		entity.SetCanShoot(true);
		entity.SetDelayToShootAgain(0.f);
		entity.SetMaxDelayToShootAgain((float)getRandomInt(1, 5));
	}
}

void CAiController::UpdateShootSystem(const float dt, CAiEntity& entity, CEntity& targetEntity)
{
	const sf::Vector2f entityPosition = entity.GetSprite().getPosition();
	const sf::Vector2f targetEntityPosition = targetEntity.GetSprite().getPosition();
	sf::Vector2f directionToTargetEntity = GetDirection(entityPosition, targetEntityPosition);

	if (!entity.GetCanShoot()) {
		UpdateDelayCanShoot(dt, entity);
	}

	if (entity.GetCanShoot()) {
		entity.GetCurrentLevel().SpawnProjectile(entity, Normalized(directionToTargetEntity), sf::Color::Red);
		entity.SetCanShoot(false);
	}
}

void CAiController::UpdateLogic(const float& dt, CAiEntity& entity, CEntity& targetEntity)
{
	const sf::Vector2f entityPosition = entity.GetSprite().getPosition();
	const sf::Vector2f entityDestination = entity.GetDestination();

	const sf::Vector2f targetEntityPosition = targetEntity.GetSprite().getPosition();


	if (VectorIsEqual(entityPosition, entityDestination, 1.f)) {
		entity.SetRandomDestination(Window);
	}

	sf::Vector2f directionToDestination = GetDirection(entityPosition, entityDestination);
	sf::Vector2f directionToTargetEntity = GetDirection(entityPosition, targetEntityPosition);
	Move(dt, entity.GetSprite(), directionToDestination.x, directionToDestination.y);

	if ((entityPosition.x != 0.f || entityPosition.y != 0.f) && (directionToTargetEntity.x != 0.f || directionToTargetEntity.y != 0.f)) {
		const float angle = GetAngleBetweenVector(directionToTargetEntity, entityPosition);
		SetRotation(entity.GetSprite(), angle);
	}
	
	UpdateShootSystem(dt, entity, targetEntity);
}
