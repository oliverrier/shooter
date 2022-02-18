#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "Scene.h"
#include "AiEntity.h"
#include "PlayerController.h"
#include "AiController.h"

class CLevel : public CScene
{

private:
    sf::Music Music;

    CEntity PlayerEntity;
    CPlayerController PlayerController;
    CAiController AiController;
    sf::RectangleShape Backgrounds[2];
    CMovementComponent MovementComponent;
    std::vector<std::vector<CAiEntity>> Waves;
    int CurrentWave = 0;

    //functions
    void InitMusic();
    void InitBackgrounds();
    void InitWaves();

public:
    CLevel(sf::RenderWindow& window, std::stack<CScene*>& states);
    virtual ~CLevel();


    virtual void UpdateInput(const float& dt);
    void UpdateBackground(const float& dt);

    void Update(const float& dt);
    void Render(sf::RenderTarget& target);

};

#endif