#pragma once
#include "Entity.h"

class CLevel;

class CPlayerEntity :
	public CEntity
{
protected:
	CLevel& CurrentLevel;
	int MaxLife = 10;
	int CurrentLife = 10;

public:
	CPlayerEntity(const char* name, sf::Sprite sprite, CLevel& CurrentLevel);
	virtual ~CPlayerEntity();

	CLevel& GetCurrentLevel();

	virtual int GetMaxLife();
	virtual void SetMaxLixfe(int maxLife);

	virtual int GetCurrentLife();
	virtual void SetCurrentLife(int currentLife);


};

