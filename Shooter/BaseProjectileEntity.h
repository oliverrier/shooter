#pragma once
#include "Entity.h"
class CBaseProjectileEntity :
	public CEntity
{
private:
	int Damage = 1;
	sf::Vector2f Direction;

public:
	CBaseProjectileEntity(const char* name, sf::Sprite sprite, sf::Vector2f direction);
	~CBaseProjectileEntity();

	bool isColliding(CEntity& other);
	const int& GetDamage();
	const sf::Vector2f& GetDirection();
};

