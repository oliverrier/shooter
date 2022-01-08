#include "Button.h"


// Constructors

CButton::CButton(float x, float y, float width, float height, sf::Font* Font, std::string Text, sf::Color IdleColor, sf::Color HoverColor, sf::Color ActiveColor)
{
	this->ButtonState = BTN_IDLE;

	this->Shape.setPosition(sf::Vector2f(x, y));
	this->Shape.setSize(sf::Vector2f(width, height));

	this->Font = Font;

	this->Text.setFont(*this->Font);
	this->Text.setString(Text);
	this->Text.setFillColor(sf::Color::White);
	this->Text.setCharacterSize(20);
	this->Text.setPosition(
		//permet de centrer le texte dans le bouton
		this->Shape.getPosition().x + this->Shape.getGlobalBounds().width / 2 - this->Text.getGlobalBounds().width / 2,
		this->Shape.getPosition().y + this->Shape.getGlobalBounds().height / 2  - this->Text.getGlobalBounds().height / 1.5
	);
	this->IdleColor = IdleColor;
	this->HoverColor = HoverColor;
	this->ActiveColor = ActiveColor;

	this->Shape.setFillColor(this->IdleColor);
}

CButton::~CButton()
{
}

//Accessors
const bool CButton::IsPressed() const {
	return this->ButtonState == BTN_ACTIVE;
}


//Functions
void CButton::Update(sf::Vector2f mousePos)
{
	// Update the booleans for hover and pressed

	//Idle
	this->ButtonState = BTN_IDLE;

	//Hover
	if (this->Shape.getGlobalBounds().contains(mousePos))
	{
		this->ButtonState = BTN_HOVER;

		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->ButtonState = BTN_ACTIVE;
		}
	}

	switch (this->ButtonState)
	{
		case BTN_IDLE:
			this->Shape.setFillColor(this->IdleColor);
			break;

		case BTN_HOVER:
			this->Shape.setFillColor(this->HoverColor);
			break;

		case BTN_ACTIVE:
			this->Shape.setFillColor(this->ActiveColor);
			break;

		default:
			this->Shape.setFillColor(sf::Color::Red);
			break;
	}
}

void CButton::Render(sf::RenderTarget* target)
{
	target->draw(this->Shape);
	target->draw(this->Text);
}

