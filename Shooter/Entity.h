#ifndef ENTITY_H
#define ENTITY_H

#include "MovementComponent.h"
 
class CEntity
{
protected:
	sf::Sprite Sprite;

	CMovementComponent* MovementComponent;
public:
	CEntity();
	virtual ~CEntity();

	//Component functions
	void SetTexture(sf::Texture& texture);
	void CreateMovementComponent(const float MaxVelocity);

	//Functions
	virtual void SetPosition(const float x, const float y);
	virtual void Move(const float dt, const float dirX, const float dirY);

	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);

};

#endif