#include "CWeapon.h"


CWeapon::CWeapon(float x, float y, float maxVelocity, sf::Texture& texture)
{
	SetTexture(texture);
	Sprite.setScale(0.5, 0.5);
	SetPosition(x, y);

	CreateMovementComponent(maxVelocity);

}

CWeapon::~CWeapon()
{
}

