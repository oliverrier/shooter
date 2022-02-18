#include "BaseProjectileController.h"
#include "BaseProjectileEntity.h"
#include "AiEntity.h"



CBaseProjectileController::CBaseProjectileController(float maxVelocity): CController(maxVelocity)
{

}


CBaseProjectileController::~CBaseProjectileController()
{
}

void CBaseProjectileController::UpdateLogic(const float& dt, CBaseProjectileEntity* entity, std::vector<CAiEntity> vectorAi, std::vector<CBaseProjectileEntity*>& playerProjectiles, int indexToRemove)
{
	float directionX = 1.f;
	float directionY = 0.f;
	Move(dt, entity->GetSprite(), directionX, directionY);

	for (auto& child : entity->GetChildEntities())
	{
		Move(dt, child.second->GetSprite(), directionX, directionY);
	}

	for (auto& ai : vectorAi)
	{
		if (entity->isColliding(ai)) {
			delete entity;
			entity = nullptr;
			playerProjectiles.erase(std::next(playerProjectiles.begin(), indexToRemove));
			return;
		}

	}


}