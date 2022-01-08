#include "Spaceship.h"



CSpaceship::CSpaceship(float x, float y, sf::Texture& texture)
{
	InitComponents();
	SetTexture(texture);
	SetPosition(x, y);
}

CSpaceship::~CSpaceship()
{
}

void CSpaceship::InitComponents()
{
	CreateMovementComponent(100.f);
}