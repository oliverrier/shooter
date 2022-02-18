#pragma once
#include "Entity.h"

class CLevel;

class CPlayerEntity :
	public CEntity
{
private:
	CLevel& CurrentLevel;
public:
	CPlayerEntity(const char* name, sf::Sprite sprite, CLevel& CurrentLevel);
	virtual ~CPlayerEntity();

	CLevel& GetCurrentLevel();
};

