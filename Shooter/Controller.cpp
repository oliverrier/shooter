
#include "Controller.h"

CController::CController(sf::RenderWindow& window, float maxVelocity):MovementComponent(*new CMovementComponent(maxVelocity)), Window(window)
{
}

CController::~CController()
{
}


void CController::Move(const float dt, sf::Sprite& sprite, const float dirX, const float dirY)
{
	MovementComponent.Move(dt, sprite, dirX, dirY); 
}

void CController::SetRotation(sf::Sprite& sprite, const float degrees)
{
	MovementComponent.SetRotation(sprite, degrees);
}

void CController::UpdateLogic(const float& dt, CEntity& entity)
{
}

