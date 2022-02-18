#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "Controller.h"

class CAiEntity;

class CAiController :
	public CController
{
public:
	CAiController(sf::RenderWindow& window, float maxVelocity);


	//functions
	void UpdateLogic(const float& dt, CAiEntity& entity, CEntity& targetEntity);
};

#endif