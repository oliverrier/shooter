#include "Entity.h"



CEntity::CEntity(): MovementComponent(nullptr)
{
}

CEntity::~CEntity()
{
}



// components functions

void CEntity::SetTexture(sf::Texture& texture)
{
	Sprite.setTexture(texture);
}


void CEntity::CreateMovementComponent(const float maxVelocity)
{
	MovementComponent = new CMovementComponent(Sprite, maxVelocity);
}

// Functions
void CEntity::Move(const float dt, const float dirX, const float dirY)
{
	if (MovementComponent)
	{
		MovementComponent->Move(dirX, dirY, dt); // Sets velocity
	}
}

void CEntity::SetPosition(const float x, const float y)
{
		Sprite.setPosition(x, y);
}

void CEntity::Update(const float& dt)
{

}

void CEntity::Render(sf::RenderTarget* target)
{
	    target->draw(Sprite);
}
