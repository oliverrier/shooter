#ifndef	WEAPON_H
#define WEAPON_H

#include "Entity.h"

class CWeapon :
    public CEntity
{
protected:
    unsigned short int Durability;
    unsigned short int DegradationByShooting;
    unsigned short int DegradationBySpecialShooting;
  
public:
    CWeapon(float x, float y, float maxVelocity, sf::Texture& texture);
    virtual ~CWeapon();

    //virtual void Shoot();
    //virtual void SpecialShoot();

};

#endif