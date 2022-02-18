#pragma once
#include "Entity.h"
class CBaseProjectileEntity :
	public CEntity
{
public:
	CBaseProjectileEntity(const char* name, sf::Sprite sprite);
	~CBaseProjectileEntity();

	bool isColliding(CEntity& other);

private:
	float Damage;
};

