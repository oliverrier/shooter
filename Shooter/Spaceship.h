#ifndef PLAYER_H
#define PLAYER_H


#include "Entity.h"

class CSpaceship :
    public CEntity
{
private:

public:
    CSpaceship(float x, float y, sf::Texture& texture);
    virtual ~CSpaceship();

    //Functions
};

#endif