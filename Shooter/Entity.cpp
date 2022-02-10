#include "Entity.h"



CEntity::CEntity(const char* name, CController& controller, std::map<const char*, CSpriteComponent> spritesComponent): Name(name), Controller(controller), SpritesComponent(spritesComponent), ParentEntity(nullptr)
{
	InitSprites();
}

CEntity::CEntity(const char* name, CController& controller, CSpriteComponent spriteComponent): Name(name), Controller(controller), ParentEntity(nullptr)
{
	SpritesComponent["root"] = spriteComponent;
	InitSprites();
}

CEntity::CEntity(const char* name, CController& controller, sf::Sprite sprite): Name(name), Controller(controller), ParentEntity(nullptr)
{
	SpritesComponent["root"] = *new CSpriteComponent(sprite);
}

CEntity::~CEntity()
{
	delete& Controller;
	ChildEntities.clear();
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




void CEntity::SetChildSprite(const char* keyName, CSpriteComponent& spriteComponent, const char* parentKey)
{
	RemoveKeyChildFromParent(keyName, spriteComponent.ParentKey);
	spriteComponent.ParentKey = parentKey;
	SpritesComponent[parentKey].ChildKeys.push_back(keyName);
	SpritesComponent[keyName] = spriteComponent;
}

std::map<const char*, CSpriteComponent>& CEntity::GetSpritesComponent()
{
	return SpritesComponent;
}

void CEntity::SetChildSprite(const char* keyName, sf::Sprite& sprite, const char* parentKey)
{
	CSpriteComponent spriteComponent = *new CSpriteComponent(sprite, parentKey);
	SpritesComponent[parentKey].ChildKeys.push_back(keyName);
	SpritesComponent[keyName] = spriteComponent;
}

void CEntity::RemoveKeyChildFromParent(const char* childKey, const char* parentKey)
{
	if (parentKey != nullptr)
	{
		std::vector<const char*>& childKeys = SpritesComponent[parentKey].ChildKeys;
		std::vector<const char*>::iterator iterator = std::find(childKeys.begin(), childKeys.end(), childKey);
		if (iterator != childKeys.end()) childKeys.erase(iterator);
	}
}

void CEntity::RemoveSprite(const char* keyName)
{
	RemoveKeyChildFromParent(keyName, SpritesComponent[keyName].ParentKey);
	SpritesComponent.erase(keyName);
}

void CEntity::SetParentEntity(CEntity* parentEntity)
{
	ParentEntity = parentEntity;
	parentEntity->ChildEntities[Name] = this;
}


void CEntity::SetChildEntity(CEntity* childEntity)
{
	childEntity->SetParentEntity(this);
}

void CEntity::DetachFromParentEntity()
{
	ParentEntity->ChildEntities.erase(Name);
	ParentEntity = nullptr;
}

void CEntity::DetachChildEntity(const char* childKey)
{
	ChildEntities[childKey]->DetachFromParentEntity();
}

void CEntity::DetachChildEntities()
{
	for (auto& child : ChildEntities)
	{
		child.second->DetachFromParentEntity();
	}
}


void CEntity::Update(const float& dt)
{
	Controller.UpdateLogic(dt, SpritesComponent);


	for (auto& child : ChildEntities)
	{
		Controller.UpdateLogic(dt, child.second->GetSpritesComponent());
	}
}

void CEntity::RecursiveSpriteRender(sf::RenderTarget* target, CSpriteComponent& spriteComponent)
{
	target->draw(spriteComponent.Sprite);

	for (const char* key : spriteComponent.ChildKeys) {
		RecursiveSpriteRender(target, SpritesComponent[key]);
	}

}

void CEntity::Render(sf::RenderTarget* target)
{
	RecursiveSpriteRender(target, SpritesComponent["root"]);
}


