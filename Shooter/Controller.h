

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "MovementComponent.h"

class CEntity;

class CController
{
protected:
	CMovementComponent& MovementComponent;

public:
	CController(float maxVelocity);
	virtual ~CController();


	//functions
	virtual void Move(const float dt, sf::Sprite& sprite, const float dirX, const float dirY);
	virtual void SetRotation(sf::Sprite& sprite, const float degrees);
	virtual void UpdateLogic(const float& dt, CEntity& entity);


};

#endif