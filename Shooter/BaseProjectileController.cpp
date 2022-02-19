#include "BaseProjectileController.h"
#include "BaseProjectileEntity.h"
#include "AiEntity.h"
#include "PlayerEntity.h"



CBaseProjectileController::CBaseProjectileController(float maxVelocity): CController(maxVelocity)
{

}


CBaseProjectileController::~CBaseProjectileController()
{
}

void CBaseProjectileController::DamagePlayerIfCollide(CBaseProjectileEntity* entity, CPlayerEntity& player, 
	std::vector<CBaseProjectileEntity*>& playerProjectiles, int indexToRemove)
{
	if (entity->GetSprite().getColor() == sf::Color::Red && entity->isColliding(player)) {
		player.SetCurrentLife(player.GetCurrentLife() - entity->GetDamage());
		delete entity;
		entity = nullptr;
		playerProjectiles.erase(std::next(playerProjectiles.begin(), indexToRemove));
		return;
	}
}

void CBaseProjectileController::DamageAiIfCollide(CBaseProjectileEntity* entity, std::vector<CAiEntity*>& vectorAi, 
	std::vector<CBaseProjectileEntity*>& playerProjectiles, int indexToRemove)
{
	for (auto& ai : vectorAi)
	{
		if (entity->GetSprite().getColor() == sf::Color::Cyan && entity->isColliding(*ai)) {
			ai->SetCurrentLife(ai->GetCurrentLife() - entity->GetDamage());
			delete entity;
			entity = nullptr;
			playerProjectiles.erase(std::next(playerProjectiles.begin(), indexToRemove));
			return;
		}

	}
}

void CBaseProjectileController::UpdateLogic(const float& dt, CBaseProjectileEntity* entity, std::vector<CAiEntity*>& vectorAi, 
	CPlayerEntity& player, std::vector<CBaseProjectileEntity*>& playerProjectiles, int indexToRemove)
{
	sf::Vector2f directionToDestination = entity->GetDirection();
	Move(dt, entity->GetSprite(), directionToDestination.x, directionToDestination.y);

	DamagePlayerIfCollide(entity, player, playerProjectiles, indexToRemove);
	DamageAiIfCollide(entity, vectorAi, playerProjectiles, indexToRemove);
}