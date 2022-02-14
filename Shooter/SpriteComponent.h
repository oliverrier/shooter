#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

//SFML
#include <SFML/Graphics.hpp>
struct SSpriteComponent
{
	sf::Sprite Sprite;
	float DefaultPositionX = 0, DefaultPositionY = 0, DefaultRotation = 0, DefaultOriginX = 0, DefaultOriginY = 0;
	float DefaultScaleX = 1, DefaultScaleY = 1;
	const char* ParentKey = nullptr;
	std::vector<const char*> ChildKeys;

	SSpriteComponent() : Sprite(sf::Sprite()) {};

	SSpriteComponent(sf::Sprite sprite) : Sprite(sprite) {};
	SSpriteComponent(sf::Sprite sprite, const char* parentKey) : Sprite(sprite), ParentKey(parentKey) {};

	SSpriteComponent(sf::Sprite sprite, float defaultScaleX, float defaultScaleY) : Sprite(sprite), DefaultScaleX(defaultScaleX), DefaultScaleY(defaultScaleY) {};

};

#endif