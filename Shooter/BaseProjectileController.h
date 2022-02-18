#pragma once
#include "Controller.h"

class CBaseProjectileEntity;

class CBaseProjectileController :
	public CController
{
public:
	CBaseProjectileController(float maxVelocity);
	~CBaseProjectileController();

	void UpdateLogic(const float& dt, CBaseProjectileEntity& entity);
};

