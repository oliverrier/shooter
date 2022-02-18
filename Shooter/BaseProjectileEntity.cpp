#include "BaseProjectileEntity.h"



CBaseProjectileEntity::CBaseProjectileEntity(const char* name, sf::Sprite sprite): CEntity(name, sprite), Damage(10.f)
{
}


CBaseProjectileEntity::~CBaseProjectileEntity()
{
}

bool CBaseProjectileEntity::isColliding(CEntity& other) 
{
	return Sprite.getGlobalBounds().intersects(other.GetSprite().getGlobalBounds());
}