#include "Button.h"


// Constructors

CButton::CButton(float x, float y, float width, float height, sf::Font& font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor):
	ButtonState(BTN_IDLE), IdleColor(idleColor), HoverColor(hoverColor), ActiveColor(activeColor)
{

	Shape.setPosition(sf::Vector2f(x, y));
	Shape.setSize(sf::Vector2f(width, height));


	Text.setFont(font);
	Text.setString(text);
	Text.setFillColor(sf::Color::White);
	Text.setCharacterSize(20);

	const float centerXOfButtons = Shape.getPosition().x + Shape.getGlobalBounds().width / 2.f - Text.getGlobalBounds().width / 2.f;
	const float centerYOfButtons = Shape.getPosition().y + Shape.getGlobalBounds().height / 2.f - Text.getGlobalBounds().height / 1.5f;

	Text.setPosition(centerXOfButtons, centerYOfButtons);

	Shape.setFillColor(IdleColor);
}

CButton::~CButton()
{
}

//Accessors
const bool CButton::IsPressed() const {
	return ButtonState == BTN_ACTIVE;
}


//Functions
void CButton::Update(sf::Vector2f mousePos)
{
	// Update the booleans for hover and pressed

	//Idle
	ButtonState = BTN_IDLE;

	//Hover
	if (Shape.getGlobalBounds().contains(mousePos))
	{
		ButtonState = BTN_HOVER;

		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			ButtonState = BTN_ACTIVE;
		}
	}

	switch (ButtonState)
	{
		case BTN_IDLE:
			Shape.setFillColor(IdleColor);
			break;

		case BTN_HOVER:
			Shape.setFillColor(HoverColor);
			break;

		case BTN_ACTIVE:
			Shape.setFillColor(ActiveColor);
			break;

		default:
			Shape.setFillColor(sf::Color::Red);
			break;
	}
}

void CButton::Render(sf::RenderTarget& target)
{
	target.draw(Shape);
	target.draw(Text);
}

