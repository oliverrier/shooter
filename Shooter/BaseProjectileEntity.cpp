#include "BaseProjectileEntity.h"



CBaseProjectileEntity::CBaseProjectileEntity(const char* name, sf::Sprite sprite, sf::Vector2f direction): CEntity(name, sprite), Direction(direction)
{
}


CBaseProjectileEntity::~CBaseProjectileEntity()
{
}

bool CBaseProjectileEntity::isColliding(CEntity& other) 
{
	return Sprite.getGlobalBounds().intersects(other.GetSprite().getGlobalBounds());
}

const int& CBaseProjectileEntity::GetDamage()
{
	return Damage;
}

const sf::Vector2f& CBaseProjectileEntity::GetDirection()
{
	return Direction;
}
