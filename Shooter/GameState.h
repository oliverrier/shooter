#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
class CGameState : public CState
{

private:
    CSpaceship* Spaceship;

    //functions
    void InitTextures();
    void InitPlayer();

public:
    CGameState(sf::RenderWindow* Window, std::stack<CState*>* States);
    virtual ~CGameState();


    virtual void UpdateInput(const float& dt);

    void Update(const float& dt);
    void Render(sf::RenderTarget* target = NULL);

};

#endif