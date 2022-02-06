#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

//SFML
#include <SFML/Graphics.hpp>
class CSpriteComponent
{
public:
	sf::Sprite Sprite;
	float DefaultPositionX, DefaultPositionY, DefaultRotation, DefaultOriginX, DefaultOriginY;
	float DefaultScaleX, DefaultScaleY;
	char* ParentKey = nullptr;
	std::vector<char*> ChildKeys;

	CSpriteComponent(sf::Sprite sprite);
	CSpriteComponent(sf::Sprite sprite, float defaultScaleX, float defaultScaleY);
};

#endif