#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include "GameState.h"
class MainMenuState :
    public State
{

private:
    //variables
    sf::RectangleShape background;


public:

    MainMenuState(sf::RenderWindow* window);
    virtual ~MainMenuState();

    // functions
    void endState();

    virtual void updateInput(const float& dt);

    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

#endif