#include "PlayerController.h"
#include "Entity.h"

CPlayerController::CPlayerController(sf::RenderWindow& window, float maxVelocity):CController(window, maxVelocity)
{
}

void CPlayerController::UpdateLogic(const float& dt, CEntity& entity)
{
	const sf::Sprite rootSprite = entity.GetSpritesComponent()["ROOT"].Sprite;
	const sf::FloatRect parentSprite = rootSprite.getGlobalBounds();
	const sf::FloatRect viewport = (sf::FloatRect) Window.getViewport(Window.getView());

	float directionX = 0.f, directionY = 0.f;
	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && parentSprite.left > viewport.left)
		--directionX;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && parentSprite.left + parentSprite.width < viewport.left + viewport.width)
		++directionX;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && parentSprite.top > viewport.top)
		--directionY;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && parentSprite.top + parentSprite.height < viewport.top + viewport.height)
		++directionY;

	MoveAllSprites(dt, entity.GetSpritesComponent(), directionX, directionY);

	for (auto& child : entity.GetChildEntities())
	{
		MoveAllSprites(dt, child.second->GetSpritesComponent(), directionX, directionY);
	}
}
