#include "SpriteComponent.h"

CSpriteComponent::CSpriteComponent(sf::Sprite sprite): Sprite(sprite), DefaultScaleX(1),
DefaultScaleY(1), DefaultPositionX(0), DefaultPositionY(0), DefaultOriginX(0), DefaultOriginY(0), DefaultRotation(0)
{
}

CSpriteComponent::CSpriteComponent(sf::Sprite sprite, float defaultScaleX, float defaultScaleY) : Sprite(sprite), DefaultScaleX(defaultScaleX), 
DefaultScaleY(defaultScaleY), DefaultPositionX(0), DefaultPositionY(0), DefaultOriginX(0), DefaultOriginY(0), DefaultRotation(0)
{
}
