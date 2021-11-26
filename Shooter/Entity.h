#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include<stack>
#include<vector>
#include<map>

//SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
 
class Entity
{
private:
protected:
	sf::RectangleShape shape;
	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	//Functions
	virtual void move(const float dt, const float dirX, const float dirY);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);

};

#endif