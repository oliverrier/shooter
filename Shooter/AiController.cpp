#include "AiController.h"
#include "AiEntity.h"

CAiController::CAiController(sf::RenderWindow& window, float maxVelocity): CController(maxVelocity), Window{window}
{

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

	if ((entityPosition.x != 0.f || entityPosition.y != 0.f) && (targetEntityPosition.x != 0.f || targetEntityPosition.y != 0.f)) {
		SetRotation(entity.GetSprite(), GetAngleBetweenVector(directionToTargetEntity, directionToDestination));
	}
}
