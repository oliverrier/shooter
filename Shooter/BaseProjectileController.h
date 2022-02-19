#pragma once
#include "Controller.h"

class CBaseProjectileEntity;
class CAiEntity;
class CPlayerEntity;

class CBaseProjectileController :
	public CController
{
public:
	CBaseProjectileController(float maxVelocity);
	~CBaseProjectileController();

	void UpdateLogic(const float& dt, CBaseProjectileEntity* entity, std::vector<CAiEntity*>& vectorAi,
		CPlayerEntity& player, std::vector<CBaseProjectileEntity*>& playerProjectiles, int indexToRemove);
};

