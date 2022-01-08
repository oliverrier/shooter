#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
class GameState : public State
{

private:
    Player* player;

    //functions
    void initTextures();
    void initPlayer();

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();


    virtual void updateInput(const float& dt);

    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);

};

#endif