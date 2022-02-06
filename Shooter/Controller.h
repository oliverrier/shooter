

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "MovementComponent.h"

class CController
{
private:
	CMovementComponent& MovementComponent;

public:
	CController(float maxVelocity);
	virtual ~CController();


	//functions
	virtual void Move(const float dt, sf::Sprite& sprite, const float dirX, const float dirY);
	virtual void UpdateLogic(const float& dt, sf::Sprite& sprite) = 0;


};

#endif