#include "Entity.h"



CEntity::CEntity(CController& controller, std::map<std::string, CSpriteComponent> spritesComponent):Controller(controller), SpritesComponent(spritesComponent)
{
	InitSprites();
}

CEntity::CEntity(CController& controller, CSpriteComponent spriteComponent) : Controller(controller)
{
	CSpriteComponent spriteComponentCopy;
	memcpy(&spriteComponentCopy, &spriteComponent, sizeof spriteComponent);
	SpritesComponent["root"] = spriteComponentCopy;
	InitSprites();
}

CEntity::CEntity(CController& controller, sf::Sprite sprite):Controller(controller)
{
	CSpriteComponent spriteComponent = { sprite };
	SpritesComponent["root"] = spriteComponent;
}

CEntity::~CEntity()
{
	delete& Controller;
}


void CEntity::InitSprites()
{
	for (auto& item : SpritesComponent) {
		CSpriteComponent& spriteComponent = item.second;
		sf::Sprite& sprite = spriteComponent.Sprite;

		sprite.setPosition(spriteComponent.DefaultPositionX, spriteComponent.DefaultPositionY);
		sprite.setScale(spriteComponent.DefaultScaleX, spriteComponent.DefaultScaleY);
		sprite.setRotation(spriteComponent.DefaultRotation);
		sprite.setOrigin(spriteComponent.DefaultOriginX, spriteComponent.DefaultOriginY);
	}
}





void CEntity::Update(const float& dt)
{
	Controller.UpdateLogic(dt, SpritesComponent);
}

void CEntity::RecursiveSpriteRender(sf::RenderTarget* target, CSpriteComponent& spriteComponent)
{
	target->draw(spriteComponent.Sprite);

	for (char* key : spriteComponent.ChildKeys) {
		RecursiveSpriteRender(target, SpritesComponent[key]);
	}


}

void CEntity::Render(sf::RenderTarget* target)
{
	RecursiveSpriteRender(target, SpritesComponent["root"]);
}


