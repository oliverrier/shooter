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
	float MaxVelocity;

	sf::Vector2f Velocity;
	sf::Vector2f Acceleration;
	sf::Vector2f Deceleration;
	// Initializer functions


public:
	CMovementComponent(float maxVelocity);
	virtual ~CMovementComponent();

	//accessors
	const sf::Vector2f& GetVelocity() const;

	//functions
	void Move(const float& dt, sf::Sprite& sprite,const float directionX, const float directionY );
	void Update(const float& dt);
};

#endif