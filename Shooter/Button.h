#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include<stack>
#include<vector>
//#include<map>

//SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};


using namespace std;

class CButton
{
	private:
		int ButtonState;

		sf::RectangleShape Shape;        
		sf::Font& Font;
		sf::Text Text;


		sf::Color IdleColor;
		sf::Color HoverColor;
		sf::Color ActiveColor;


	public:
		// Constructors
		CButton(float x, float y, float width, float height, sf::Font& Font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
		~CButton();

		//Accessors
		const bool IsPressed() const;

		//Functions
		void Update(const sf::Vector2f mousePos);
		void Render(sf::RenderTarget& target);

};

#endif