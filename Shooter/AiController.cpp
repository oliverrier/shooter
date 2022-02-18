#include "AiController.h"
#include "AiEntity.h"

CAiController::CAiController(sf::RenderWindow& window, float maxVelocity): CController(window, maxVelocity)
{

}

void CAiController::UpdateLogic(const float& dt, CAiEntity& entity)
{
	std::cout << entity.GetDestination().x << std::endl;
}
