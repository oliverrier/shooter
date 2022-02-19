 #ifndef GAMESTATE_H
#define GAMESTATE_H


#include "Scene.h"
#include "AiEntity.h"
#include "PlayerEntity.h"
#include "BaseWeaponEntity.h"
#include "PlayerController.h"
#include "AiController.h"
#include "BaseProjectileController.h"

class CLevel : public CScene
{

private:
    sf::Music Music;

    CPlayerEntity PlayerEntity;
	CPlayerController PlayerController;
	CBaseProjectileController ProjectileController;
    CAiController AiController;
    sf::RectangleShape Backgrounds[2];
    CMovementComponent MovementComponent;
    std::vector<std::vector<CAiEntity*>> Waves;
    int CurrentWave = 0;
	std::vector<CBaseProjectileEntity*> PlayerProjectiles;
    sf::Text TextLife;
    sf::Text TextEnd;
    sf::Font Font;
    bool IsEnd = false;
    float DelayToEndGame = 0.f;
    float DelayToNextWave = 0.f;

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
	void SpawnProjectile(CEntity& entity, sf::Vector2f direction, sf::Color color);
};

#endif