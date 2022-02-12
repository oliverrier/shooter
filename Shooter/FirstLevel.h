#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "Scene.h"
class CFirstLevel : public CScene
{

private:
    sf::Music Music;

    CEntity& SpaceshipPlayer;
    std::deque<sf::RectangleShape> Backgrounds;
    CMovementComponent MovementComponent;


    //functions
    void InitMusic();
    void AddBackground(float positionX);

public:
    CFirstLevel(sf::RenderWindow& window, std::stack<CScene*>& states);
    virtual ~CFirstLevel();


    virtual void UpdateInput(const float& dt);
    void UpdateBackground(const float& dt);

    void Update(const float& dt);
    void Render(sf::RenderTarget& target);

};

#endif