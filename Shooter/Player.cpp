#include "Player.h"



Player::Player(float x, float y, sf::Texture& texture)
{
	this->initComponents();
	this->setTexture(texture);
	this->setPosition(x, y);
}

Player::~Player()
{
}

void Player::initComponents()
{
	this->createMovementComponent(100.f);
}