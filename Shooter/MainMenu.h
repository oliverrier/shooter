#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include "FirstLevel.h"
#include "Button.h"
 
 
class CMainMenu :
    public CScene
{

private:
    //variables
    sf::Music Music;
    sf::RectangleShape Background;
    sf::Font Font;

    std::map<std::string, CButton*> Buttons;

    //Functions
    void InitBackground();
    void InitMusic();
    void InitFonts();
    void InitButtons();


public:

    CMainMenu(sf::RenderWindow& window, std::stack<CScene*>& states);
    virtual ~CMainMenu();

    void UpdateInput(const float& dt);
    void UpdateButtons();
    void RenderButtons(sf::RenderTarget& target);
    void Update(const float& dt);
    void Render(sf::RenderTarget& target);
};

#endif