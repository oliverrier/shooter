#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

//SFML
#include <SFML/Graphics.hpp>
class CSpriteComponent
{
public:
	sf::Sprite Sprite;
	float DefaultPositionX, DefaultPositionY, DefaultRotation, DefaultOriginX, DefaultOriginY = 0;
	float DefaultScaleX, DefaultScaleY = 1;
	const char* ParentKey = nullptr;
	std::vector<const char*> ChildKeys;

	CSpriteComponent() : Sprite(*new sf::Sprite()) {};

	CSpriteComponent(sf::Sprite sprite) : Sprite(sprite) {};
	CSpriteComponent(sf::Sprite sprite, const char* parentKey) : Sprite(sprite), ParentKey(parentKey) {};

	CSpriteComponent(sf::Sprite sprite, float defaultScaleX, float defaultScaleY) : Sprite(sprite), DefaultScaleX(defaultScaleX), DefaultScaleY(defaultScaleY) {};

};

#endif