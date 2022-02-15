#include "PlayerController.h"
#include "Entity.h"

CPlayerController::CPlayerController(sf::RenderWindow& window, float maxVelocity):CController(window, maxVelocity)
{
}

void CPlayerController::UpdateLogic(const float& dt, CEntity& entity)
{
	const sf::FloatRect globalBounds = entity.GetSprite().getGlobalBounds();
	const sf::FloatRect viewport = (sf::FloatRect) Window.getViewport(Window.getView());

	float directionX = 0.f, directionY = 0.f;
	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && globalBounds.left > viewport.left)
		--directionX;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && globalBounds.left + globalBounds.width < viewport.left + viewport.width)
		++directionX;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && globalBounds.top > viewport.top)
		--directionY;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && globalBounds.top + globalBounds.height < viewport.top + viewport.height)
		++directionY;

	std::cout << "bite" << std::endl;
	Move(dt, entity.GetSprite(), directionX, directionY);

	for (auto& child : entity.GetChildEntities())
	{
		Move(dt, child.second->GetSprite(), directionX, directionY);
	}
}
