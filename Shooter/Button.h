#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Button
{
	private:
		sf::RectangleShape base;        

		sf::Text text;
		sf::Text textHover;

		sf::Color baseColor;
		sf::Color baseColorHover;


	public:
		// Constructors
		Button(sf::Vector2f position, sf::Vector2f size, sf::Text text, sf::Text textHover, sf::Color backgroundColor, sf::Color backgroundColorHover);

		//getters and setters
		void setText(sf::Text text);
		sf::Text getText() const;

	

		//others methods
		void setPosition(sf::Vector2f vector2f);

		void draw(sf::RenderWindow& window);

};

#endif