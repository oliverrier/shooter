#include "PlayerController.h"

CPlayerController::CPlayerController(float maxVelocity):CController(maxVelocity)
{
}

void CPlayerController::UpdateLogic(const float& dt, std::map<const char*, CSpriteComponent>& spritesComponent)
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

	MoveAllSprites(dt, spritesComponent, directionX, directionY);
}
