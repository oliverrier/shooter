#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include "Level.h"
#include "Button.h"


class CPauseMenu :
    public CScene
{

private:
    //variables
    sf::RectangleShape Background;
    sf::Font Font;
    sf::Text TitlePauseMenu;


    std::map<std::string, CButton*> Buttons;

    //Functions
    void InitBackground();
    void InitFonts();
    void InitTitlePauseMenu();
    void InitButtons();


public:

    CPauseMenu(sf::RenderWindow& window, std::stack<CScene*>& states);
    virtual ~CPauseMenu();

    void UpdateInput(const float& dt);
    void UpdateButtons();
    void RenderButtons(sf::RenderTarget& target);
    void Update(const float& dt);
    void Render(sf::RenderTarget& target);
};

#endif