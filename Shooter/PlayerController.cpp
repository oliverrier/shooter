#include "PlayerController.h"
#include "Entity.h"

CPlayerController::CPlayerController(float maxVelocity):CController(maxVelocity)
{
}

void CPlayerController::UpdateLogic(const float& dt, CEntity& entity)
{
	float directionX = 0.f, directionY = 0.f;

	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		--directionX;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		++directionX;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		--directionY;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		++directionY;

	MoveAllSprites(dt, entity.GetSpritesComponent(), directionX, directionY);

	for (auto& child : entity.GetChildEntities())
	{
		MoveAllSprites(dt, child.second->GetSpritesComponent(), directionX, directionY);
	}
}
