#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include "GameState.h"
#include "Button.h"
 
 
class MainMenuState :
    public State
{

private:
    //variables
    sf::Texture textureBackground;
    sf::RectangleShape background;
    sf::Font font;

  std::map<std::string, Button*> buttons;

    //Functions
  void initVariables();
    void initBackground();
    void initFonts();
    void initButtons();


public:

    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MainMenuState();

    void updateInput(const float& dt);
    void updateButtons();
    void renderButtons(sf::RenderTarget* target = NULL);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

#endif