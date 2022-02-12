#include "MovementComponent.h"

CMovementComponent::CMovementComponent(float MaxVelocity): MaxVelocity(MaxVelocity)
{
}

CMovementComponent::~CMovementComponent()
{
}


//functions
void CMovementComponent::Move(const float& dt, sf::Sprite& sprite, const float directionX, const float directionY)
{

	//Penser à faire un normalize
	Velocity.x = directionX;
	Velocity.y = directionY;


	sprite.move(Normalize(Velocity) * MaxVelocity * dt); // Uses velocity

}

void CMovementComponent::Update(const float& dt)
{
}



const sf::Vector2f& CMovementComponent::GetVelocity() const
{
	return Velocity;
}