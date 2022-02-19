#include "PlayerEntity.h"
#include <iostream>


CPlayerEntity::CPlayerEntity(const char* name, sf::Sprite sprite, CLevel& currentLevel) :CEntity(name, sprite), CurrentLevel{currentLevel}
{
}


CPlayerEntity::~CPlayerEntity()
{
}

CLevel& CPlayerEntity::GetCurrentLevel() {
	return CurrentLevel;
}
int CPlayerEntity::GetMaxLife()
{
	return MaxLife;
}
void CPlayerEntity::SetMaxLixfe(int maxLife)
{
	MaxLife = maxLife;
}
int CPlayerEntity::GetCurrentLife()
{
	return CurrentLife;
}
void CPlayerEntity::SetCurrentLife(int currentLife)
{
	CurrentLife = currentLife;
}
;

