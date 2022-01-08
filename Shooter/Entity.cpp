#include "Entity.h"



Entity::Entity(): movementComponent(nullptr)
{
}

Entity::~Entity()
{
}



// components functions

void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}


void Entity::createMovementComponent(const float maxVelocity)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity);
}

// Functions
void Entity::move(const float dt, const float dirX, const float dirY)
{
	if (this->movementComponent)
	{
		this->movementComponent->move(dirX, dirY, dt); // Sets velocity
	}
}

void Entity::setPosition(const float x, const float y)
{
		this->sprite.setPosition(x, y);
}

void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget* target)
{
	    target->draw(this->sprite);
}
