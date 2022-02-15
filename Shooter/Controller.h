

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "MovementComponent.h"

class CEntity;

class CController
{
protected:
	CMovementComponent& MovementComponent;
	sf::RenderWindow& Window;

public:
	CController(sf::RenderWindow& window, float maxVelocity);
	virtual ~CController();


	//functions
	virtual void Move(const float dt, sf::Sprite& sprite, const float dirX, const float dirY);
	virtual void UpdateLogic(const float& dt, CEntity& entity);


};

#endif