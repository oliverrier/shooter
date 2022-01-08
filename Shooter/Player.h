#ifndef PLAYER_H
#define PLAYER_H


#include "Entity.h"
class Player :
    public Entity
{
private:
    //Variabmles

    //Initializer functions
    void initComponents();

public:
    Player(float x, float y, sf::Texture& texture);
    virtual ~Player();

    //Functions
};

#endif