#pragma once
#include "PlayerEntity.h"

class CAiEntity :
    public CPlayerEntity
{
private:
    sf::Vector2f Destination;
    bool CanShoot = false;
    float DelayToShootAgain = 0.f;
    float MaxDelayToShootAgain;

public:
    CAiEntity(const char* name, sf::Sprite sprite, CLevel& CurrentLevel);
    virtual ~CAiEntity();

    const sf::Vector2f& GetDestination();
    void SetDestination(sf::Vector2f newDestination);
    void SetRandomDestination(sf::RenderWindow& Window);

    //getter and setter
    bool& GetCanShoot();
    void SetCanShoot(bool canShoot);

    const float& GetDelayToShootAgain();
    void SetDelayToShootAgain(float delayToShootAgain);

    const float& GetMaxDelayToShootAgain();
    void SetMaxDelayToShootAgain(float maxDelayToShootAgain);
};

