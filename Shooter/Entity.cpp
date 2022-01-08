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
	this->Sprite.setTexture(texture);
}


void CEntity::CreateMovementComponent(const float MaxVelocity)
{
	this->MovementComponent = new CMovementComponent(this->Sprite, MaxVelocity);
}

// Functions
void CEntity::Move(const float dt, const float dirX, const float dirY)
{
	if (this->MovementComponent)
	{
		this->MovementComponent->Move(dirX, dirY, dt); // Sets velocity
	}
}

void CEntity::SetPosition(const float x, const float y)
{
		this->Sprite.setPosition(x, y);
}

void CEntity::Update(const float& dt)
{

}

void CEntity::Render(sf::RenderTarget* target)
{
	    target->draw(this->Sprite);
}
