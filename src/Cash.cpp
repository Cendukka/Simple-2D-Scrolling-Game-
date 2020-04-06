#include "Cash.h"
#include "Game.h"
#include "Util.h"
#include "GLM/gtx/rotate_vector.hpp"
#include "Level1Scene.h"
#include "GLM/gtx/string_cast.hpp"
#include "ScoreBoardManager.h"
#include "RoadLocation.h"

Cash::Cash(int selectedRoad)
{
	TheTextureManager::Instance()->load("../Assets/Cash.png",
		"cash", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("cash");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(400.0f, -20.0f));
	setIsColliding(false);
	setType(GameObjectType::CASH);
	setCurrentRoad(RoadLocation::ROAD_MIDDLE);
	setMovingSpeed(2.0);
	setActive(true);
	setCurrentRoad(selectedRoad);
	draw(getCurrentRoad());
}

Cash::~Cash()
{
}

void Cash::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;




	TheTextureManager::Instance()->draw("cash", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Cash::update()
{
	//Move the enemies forward
		
	setPosition(glm::vec2(getPosition().x, getPosition().y + getMovingSpeed()));
	std::cout << Util::RandomRangeInt(-200, 0) <<std::endl;
	
	if (getPosition().y >= Config::SCREEN_WIDTH) {
		
		draw(Util::RandomRangeInt(0,4));
	}
}

void Cash::clean()
{
	draw(Util::RandomRangeInt(0, 4));
	setIsColliding(false);
}
void Cash::setActive(bool active)
{
	m_isActive = active;
}

void Cash::setAlpha(Uint8 value)
{
	m_alpha = value;
}

bool Cash::isActive()
{
	return m_isActive;
}



int Cash::getCurrentRoad()
{
	return m_currentRoad;
}

void Cash::setCurrentRoad(int currentRoad)
{
	m_currentRoad = currentRoad;
}

int Cash::getMovingSpeed()
{
	return m_movingSpeed;
}

void Cash::setMovingSpeed(float newMovingSpeed)
{
	m_movingSpeed = newMovingSpeed;
}





//Drawing 
void Cash::draw(int roadLoation)
{
	
	switch(roadLoation)
	{
	case ROAD_LEFT:
		setPosition(glm::vec2(85.0, Util::RandomRangeInt(-200, 0)));
		break;
	case ROAD_MIDDLE_LEFT:
		setPosition(glm::vec2(245.0, Util::RandomRangeInt(-200, 0)));
		break;
	case ROAD_MIDDLE:
		setPosition(glm::vec2(405.0, Util::RandomRangeInt(-200, 0)));
		break;
	case ROAD_MIDDLE_RIGHT:
		setPosition(glm::vec2(565.0, Util::RandomRangeInt(-200, 0)));
		break;
	case ROAD_RIGHT:
		setPosition(glm::vec2(725.0, Util::RandomRangeInt(-200, 0)));
		break;
	default:
		break;
	}
	
}
