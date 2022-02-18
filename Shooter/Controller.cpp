
#include "Controller.h"

CController::CController(float maxVelocity):MovementComponent(*new CMovementComponent(maxVelocity))
{
}

CController::~CController()
{
}


void CController::Move(const float dt, sf::Sprite& sprite, const float dirX, const float dirY)
{
	MovementComponent.Move(dt, sprite, dirX, dirY); // Sets velocity
}

void CController::UpdateLogic(const float& dt, CEntity& entity)
{
}

