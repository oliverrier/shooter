#include "BaseWeaponEntity.h"
#include "TextureDictionary.h"



CBaseWeaponEntity::CBaseWeaponEntity(const char* name, sf::Sprite sprite): CEntity(name, sprite)
{
}


CBaseWeaponEntity::~CBaseWeaponEntity()
{
}

//void CBaseWeaponEntity::Use() {
//	// No clue how to stock a Type to be used later in cpp
//
//	CBaseProjectileEntity* projectile = new CBaseProjectileEntity("BASE_PROJECTILE", sf::Sprite(CTextureDictionary::GetTexture("BASE_PROJECTILE")));
//	projectile->GetSprite().setPosition(GetPositionMiddleRight(projectile->GetSprite(), Sprite));
//}
