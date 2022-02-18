#pragma once
#include "Entity.h"
class CAiEntity :
    public CEntity
{
private:
    sf::Vector2f Destination;

public:
    CAiEntity(const char* name, sf::Sprite sprite);

    const sf::Vector2f& GetDestination();
    void SetDestination(sf::Vector2f newDestination);

};

