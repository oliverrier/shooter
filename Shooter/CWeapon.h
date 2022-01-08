#ifndef	WEAPON_H
#define WEAPON_H

#include "Entity.h"

class CWeapon :
    public CEntity
{
private:
  
public:
    CWeapon(float x, float y, float maxVelocity, sf::Texture& texture);
    virtual ~CWeapon();

};

#endif