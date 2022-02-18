#include "Weapon.h"


CWeapon::CWeapon(float x, float y, float maxVelocity, sf::Texture& texture):Durability(1000.f), DegradationByShooting(100.f), DegradationBySpecialShooting(200.f)
{
	SetTexture(texture);
	Sprite.setScale(0.5, 0.5);
	SetPosition(x, y);

	CreateMovementComponent(maxVelocity);

}

CWeapon::~CWeapon()
{
}

