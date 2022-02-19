#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Controller.h"

class CPlayerEntity;

class CPlayerController :
	public CController

{
protected:
	sf::RenderWindow& Window;
	bool canShoot = true;
	float delayToShootAgain = 0.f;

public:
	CPlayerController(sf::RenderWindow& window, float maxVelocity);


	//functions
	void MovePlayer(const float dt, CPlayerEntity& player);
	void UpdateDelayCanShoot(const float dt);
	void UpdateShootSystem(const float dt, CPlayerEntity& player);
	void UpdateLogic(const float& dt, CPlayerEntity& entity);
};

#endif