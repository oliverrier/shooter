#include "Spaceship.h"



CSpaceship::CSpaceship(float x, float y, sf::Texture& texture)
{
	SetTexture(texture);
	Sprite.setScale(0.5, 0.5);
	SetPosition(x, y);

	CreateMovementComponent(50.f);

	InitTextures();
}

CSpaceship::~CSpaceship()
{
}

//inits
void CSpaceship::InitTextures() {

}


// functions

//void CSpaceship::AddWeapon(CWeapon& weapon) {
//	Weapon = weapon;
//}



void CSpaceship::Update(const float& dt)
{
	UpdateInput(dt);

}

void CSpaceship::UpdateInput(const float& dt)
{

	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		Move(dt, -5.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		Move(dt, 5.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		Move(dt, 0.f, -5.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		Move(dt, 0.f, 5.f);
}

