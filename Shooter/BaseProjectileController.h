#pragma once
#include "Controller.h"

class CBaseProjectileController :
	public CController
{
public:
	CBaseProjectileController(float maxVelocity);
	~CBaseProjectileController();

	void UpdateLogic(const float& dt, CEntity& entity);
};

