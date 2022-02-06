#ifndef ENTITY_H
#define ENTITY_H

#include "PlayerController.h"
 

class CEntity
{
protected:
	sf::Sprite Sprite;

	CController& Controller;
public:
	CEntity(CController& controller, sf::Sprite sprite, float positionX, float positionY);
	virtual ~CEntity();


	//Functions
	virtual void SetPosition(const float x, const float y);

	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);

};

#endif