#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Controller.h"



class CPlayerController :
    public CController
{
public:
	CPlayerController(float maxVelocity);


	//functions
	void UpdateLogic(const float& dt, std::map<const char*, CSpriteComponent>& spritesComponent);
};

#endif