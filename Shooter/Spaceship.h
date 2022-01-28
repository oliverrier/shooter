#ifndef PLAYER_H
#define PLAYER_H


#include "Entity.h"
#include "Weapon.h"

class CSpaceship :
    public CEntity
{
private:
    CWeapon* Weapon;

    //functions
    void InitTextures();
public:
    CSpaceship(float x, float y, sf::Texture& texture);
    virtual ~CSpaceship();

   

    //Functions
    void Update(const float& dt);
    void UpdateInput(const float& dt);
    void AddWeapon(CWeapon& weapon);
};

#endif