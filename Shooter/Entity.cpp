#include "Entity.h"



CEntity::CEntity(CController& controller, sf::Sprite sprite, float positionX, float positionY):Controller(controller), Sprite(sprite)
{
	Sprite.setScale(0.5, 0.5);
	SetPosition(positionX, positionY);
}

CEntity::~CEntity()
{
	delete& Controller;
}




// Functions


void CEntity::SetPosition(const float x, const float y)
{
    Sprite.setPosition(x, y);
}

void CEntity::Update(const float& dt)
{
	Controller.UpdateLogic(dt, Sprite);
}

void CEntity::Render(sf::RenderTarget* target)
{
	target->draw(Sprite);
}
