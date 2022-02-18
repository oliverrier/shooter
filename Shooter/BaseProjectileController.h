#pragma once
#include "Controller.h"

class CBaseProjectileEntity;
class CAiEntity;

class CBaseProjectileController :
	public CController
{
public:
	CBaseProjectileController(float maxVelocity);
	~CBaseProjectileController();

	void UpdateLogic(const float& dt, CBaseProjectileEntity* entity, std::vector<CAiEntity> vectorAi, std::vector<CBaseProjectileEntity*>& pslayerProjectiles, int indexToRemove);
};

