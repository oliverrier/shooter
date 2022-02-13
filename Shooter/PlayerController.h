#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Controller.h"



class CPlayerController :
    public CController
{
public:
	CPlayerController(sf::RenderWindow& window, float maxVelocity);


	//functions
	void UpdateLogic(const float& dt, CEntity& entity);
};

#endif