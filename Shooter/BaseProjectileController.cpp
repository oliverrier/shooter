#include "BaseProjectileController.h"
#include "BaseProjectileEntity.h"



CBaseProjectileController::CBaseProjectileController(float maxVelocity): CController(maxVelocity)
{

}


CBaseProjectileController::~CBaseProjectileController()
{
}

void CBaseProjectileController::UpdateLogic(const float& dt, CBaseProjectileEntity& entity)
{
	float directionX = 1.f;
	float directionY = 0.f;
	Move(dt, entity.GetSprite(), directionX, directionY);

	for (auto& child : entity.GetChildEntities())
	{
		Move(dt, child.second->GetSprite(), directionX, directionY);
	}

}