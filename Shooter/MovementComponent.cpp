#include "MovementComponent.h"

CMovementComponent::CMovementComponent(sf::Sprite& Sprite, float MaxVelocity): Sprite(Sprite), MaxVelocity(MaxVelocity)
{
}

CMovementComponent::~CMovementComponent()
{
}


//functions
void CMovementComponent::Move(const float dirX, const float dirY, const float& dt)
{
	this->Velocity.x = this->MaxVelocity * dirX;
	this->Velocity.y = this->MaxVelocity * dirY;

	this->Sprite.move(this->Velocity * dt); // Uses velocity

}

void CMovementComponent::Update(const float& dt)
{
}



const sf::Vector2f& CMovementComponent::GetVelocity() const
{
	return this->Velocity;
}

