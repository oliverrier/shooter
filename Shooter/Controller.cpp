
#include "Controller.h"

CController::CController(sf::RenderWindow& window, float maxVelocity):MovementComponent(*new CMovementComponent(maxVelocity)), Window(window)
{
}

CController::~CController()
{
	delete &MovementComponent;
}


void CController::Move(const float dt, sf::Sprite& sprite, const float dirX, const float dirY)
{
	MovementComponent.Move(dt, sprite, dirX, dirY); // Sets velocity
}


void CController::MoveAllSprites(const float dt, std::map<const char*, SSpriteComponent>& spritesComponent, const float dirX, const float dirY)
{
	for (auto& sprite : spritesComponent)
	{
		Move(dt, sprite.second.Sprite, dirX, dirY); // Sets velocity
	}
}


