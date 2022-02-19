#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "Controller.h"

class CAiEntity;

class CAiController :
	public CController
{
protected:
	sf::RenderWindow& Window;
public:
	CAiController(sf::RenderWindow& window, float maxVelocity);

	//functions
	void UpdateDelayCanShoot(const float dt, CAiEntity& entity);
	void UpdateShootSystem(const float dt, CAiEntity& entity, CEntity& targetEntity);
	void UpdateLogic(const float& dt, CAiEntity& entity, CEntity& targetEntity);
};

#endif