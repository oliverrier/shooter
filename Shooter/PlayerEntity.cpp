#include "PlayerEntity.h"



CPlayerEntity::CPlayerEntity(const char* name, sf::Sprite sprite, CLevel& currentLevel) :CEntity(name, sprite), CurrentLevel{currentLevel}
{
}


CPlayerEntity::~CPlayerEntity()
{
}

CLevel& CPlayerEntity::GetCurrentLevel() {
	return CurrentLevel;
};

