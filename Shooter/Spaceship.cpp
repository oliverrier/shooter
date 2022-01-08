#include "Spaceship.h"



CSpaceship::CSpaceship(float x, float y, sf::Texture& texture)
{
	this->InitComponents();
	this->SetTexture(texture);
	this->SetPosition(x, y);
}

CSpaceship::~CSpaceship()
{
}

void CSpaceship::InitComponents()
{
	this->CreateMovementComponent(100.f);
}