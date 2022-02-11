#include "PlayerController.h"
#include "Entity.h"

CPlayerController::CPlayerController(float maxVelocity):CController(maxVelocity)
{
}

void CPlayerController::UpdateLogic(const float& dt, CEntity& entity)
{
	float directionX = 0;
	float directionY = 0;

	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		directionX = -5.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		directionX = 5.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		directionY = -5.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		directionY = 5.f;

	MoveAllSprites(dt, entity.GetSpritesComponent(), directionX, directionY);

	for (auto& child : entity.GetChildEntities())
	{
		MoveAllSprites(dt, child.second->GetSpritesComponent(), directionX, directionY);
	}
}
