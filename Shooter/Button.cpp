#include "Button.h"


// Constructors
Button::Button(sf::Vector2f position, sf::Vector2f size, 
    sf::Text text, sf::Text textHover, 
    sf::Color backgroundColor, sf::Color backgroundColorHover)
    : 
    text(text), textHover(textHover), baseColor(backgroundColor), baseColorHover(backgroundColorHover)
{
    this->base.setPosition(position);
    this->base.setSize(size);
    this->base.setFillColor(backgroundColor);

    this->text.setPosition(
        this->base.getPosition().x + (this->text.getGlobalBounds().width / 2.f) / 2.f - this->text.getGlobalBounds().width / 2.f,
        this->base.getPosition().y + (this->text.getGlobalBounds().height / 2.f)  / 2.f - this->text.getGlobalBounds().height / 2.f
    ); 
}

//getters and setters
void Button::setText(sf::Text text)
{
    this->text = text;
}

sf::Text Button::getText() const
{
    return this->text;
}


//others methods
void Button::setPosition(sf::Vector2f vector2f)
{
    this->text.setPosition(vector2f);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(this->base);
    window.draw(this->text);
};


