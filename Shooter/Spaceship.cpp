#include "Spaceship.h"



CSpaceship::CSpaceship(float x, float y, sf::Texture& texture)
{
	SetTexture(texture);
	Sprite.setScale(0.5, 0.5);
	SetPosition(x, y);

	CreateMovementComponent(50.f);

}

CSpaceship::~CSpaceship()
{
}

