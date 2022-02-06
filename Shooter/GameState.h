#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
class CGameState : public CState
{

private:
    sf::Music Music;

    CEntity* SpaceshipPlayer;

    //functions
    void InitTextures();
    void InitMusic();
    void InitPlayer();

public:
    CGameState(sf::RenderWindow* window, std::stack<CState*>* states);
    virtual ~CGameState();


    virtual void UpdateInput(const float& dt);

    void Update(const float& dt);
    void Render(sf::RenderTarget* target = NULL);

};

#endif