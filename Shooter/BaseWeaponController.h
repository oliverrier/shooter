#pragma once

#include "Controller.h"

class CBaseWeaponController :
	public CController
{
public:
	CBaseWeaponController(float maxVelocity);
	void Use();
};

