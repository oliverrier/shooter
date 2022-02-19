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


	void DamagePlayerIfCollide(CBaseProjectileEntity* entity,
		CPlayerEntity& player, std::vector<CBaseProjectileEntity*>& playerProjectiles, int indexToRemove);
	void DamageAiIfCollide(CBaseProjectileEntity* entity, std::vector<CAiEntity*>& vectorAi,
		std::vector<CBaseProjectileEntity*>& playerProjectiles, int indexToRemove);

	void UpdateLogic(const float& dt, CBaseProjectileEntity* entity, std::vector<CAiEntity*>& vectorAi,
		CPlayerEntity& player, std::vector<CBaseProjectileEntity*>& playerProjectiles, int indexToRemove);

};

