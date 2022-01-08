#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include <iostream>
#include<stack>
#include<vector>
#include<map>

//SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class MovementComponent
{
private:
	sf::Sprite& sprite;

	float maxVelocity;

	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;
	// Initializer functions


public:
	MovementComponent(sf::Sprite& sprite, float maxVelocity);
	virtual ~MovementComponent();

	//accessors
	const sf::Vector2f& getVelocity() const;

	//functions
	void move(const float dirX, const float dirY, const float& dt);
	void update(const float& dt);
};

#endif