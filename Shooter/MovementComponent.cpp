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
	Velocity.x = directionX;
	Velocity.y = directionY;

	sprite.move(Normalized(Velocity) * MaxVelocity * dt);
}

void CMovementComponent::Move(const float& dt, sf::Shape& shape, const float directionX, const float directionY)
{
	Velocity.x = directionX;
	Velocity.y = directionY;

	shape.move(Normalized(Velocity) * MaxVelocity * dt);
}

void CMovementComponent::SetRotation(sf::Sprite& sprite, const float degrees)
{
	sprite.setRotation(degrees);
}

void CMovementComponent::Update(const float& dt)
{
}



const sf::Vector2f& CMovementComponent::GetVelocity() const
{
	return Velocity;
}