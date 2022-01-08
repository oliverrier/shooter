#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include "GameState.h"
#include "Button.h"
 
 
class CMainMenuState :
    public CState
{

private:
    //variables
    sf::Texture TextureBackground;
    sf::RectangleShape Background;
    sf::Font Font;

    std::map<std::string, CButton*> Buttons;

    //Functions
    void InitVariables();
    void InitBackground();
    void InitFonts();
    void InitButtons();


public:

    CMainMenuState(sf::RenderWindow* Window, std::stack<CState*>* states);
    virtual ~CMainMenuState();

    void UpdateInput(const float& dt);
    void UpdateButtons();
    void RenderButtons(sf::RenderTarget* target = NULL);
    void Update(const float& dt);
    void Render(sf::RenderTarget* target = NULL);
};

#endif