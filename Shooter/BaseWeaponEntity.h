#pragma once
#include "Entity.h"
#include "BaseProjectileEntity.h"


class CBaseWeaponEntity :
	public CEntity
{
public:
	CBaseWeaponEntity(const char* name, sf::Sprite sprite);
	~CBaseWeaponEntity();

	//void Use();
};

