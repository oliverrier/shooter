#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "Scene.h"

class CLevel : public CScene
{

private:
    sf::Music Music;

    CEntity PlayerEntity;
    CPlayerController PlayerController;
    sf::RectangleShape Backgrounds[2];
    CMovementComponent MovementComponent;

    //functions
    void InitMusic();
    void InitBackgrounds();

public:
    CLevel(sf::RenderWindow& window, std::stack<CScene*>& states);
    virtual ~CLevel();


    virtual void UpdateInput(const float& dt);
    void UpdateBackground(const float& dt);

    void Update(const float& dt);
    void Render(sf::RenderTarget& target);

};

#endif