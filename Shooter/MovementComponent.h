#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include<iostream>
#include<stack>
#include<vector>
#include<map>

//SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "TexturesManager.h"

class CMovementComponent
{
private:
	sf::Sprite& Sprite;

	float MaxVelocity;

	sf::Vector2f Velocity;
	sf::Vector2f Acceleration;
	sf::Vector2f Deceleration;
	// Initializer functions


public:
	CMovementComponent(sf::Sprite& sprite, float maxVelocity);
	virtual ~CMovementComponent();

	//accessors
	const sf::Vector2f& GetVelocity() const;

	//functions
	void Move(const float dirX, const float dirY, const float& dt);
	void Update(const float& dt);
};

#endif