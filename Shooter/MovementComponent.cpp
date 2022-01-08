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
	Velocity.x = MaxVelocity * dirX;
	Velocity.y = MaxVelocity * dirY;

	Sprite.move(Velocity * dt); // Uses velocity

}

void CMovementComponent::Update(const float& dt)
{
}



const sf::Vector2f& CMovementComponent::GetVelocity() const
{
	return Velocity;
}

