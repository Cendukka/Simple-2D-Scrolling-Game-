#include "Dynamite.h"
#include "Game.h"
#include "Util.h"
#include "GLM/gtx/rotate_vector.hpp"
#include "Level1Scene.h"
#include "GLM/gtx/string_cast.hpp"
#include "ScoreBoardManager.h"
#include "RoadLocation.h"

Dynamite::Dynamite(int selectedRoad)
{
	TheTextureManager::Instance()->load("../Assets/Dynamite.png",
		"dynamite", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("dynamite");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(400.0f, -20.0f));
	setIsColliding(false);
	setType(GameObjectType::DYNAMITE);
	setCurrentRoad(RoadLocation::ROAD_MIDDLE);
	setMovingSpeed(2.0);
	setActive(true);
	setCurrentRoad(selectedRoad);
	draw(Util::RandomRangeInt(0, 4));
}

Dynamite::~Dynamite()
{
}

void Dynamite::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;




	TheTextureManager::Instance()->draw("dynamite", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Dynamite::update()
{
	//Move the enemies forward
		
	setPosition(glm::vec2(getPosition().x, getPosition().y + getMovingSpeed()));
	std::cout << Util::RandomRangeInt(-200, 0) <<std::endl;
	//if the Dynamite's y position is over screen, change it position back to up
	if (getPosition().y >= Config::SCREEN_WIDTH) {
		//draw the cash again on a random road
		draw(Util::RandomRangeInt(ROAD_LEFT, ROAD_RIGHT));
	}
}

void Dynamite::clean()
{
	draw(Util::RandomRangeInt(0, 4));
	setIsColliding(false);
}
void Dynamite::setActive(bool active)
{
	m_isActive = active;
}

void Dynamite::setAlpha(Uint8 value)
{
	m_alpha = value;
}

bool Dynamite::isActive()
{
	return m_isActive;
}



int Dynamite::getCurrentRoad()
{
	return m_currentRoad;
}

void Dynamite::setCurrentRoad(int currentRoad)
{
	m_currentRoad = currentRoad;
}

int Dynamite::getMovingSpeed()
{
	return m_movingSpeed;
}

void Dynamite::setMovingSpeed(float newMovingSpeed)
{
	m_movingSpeed = newMovingSpeed;
}





//Drawing the dynamite into new position above the screen on a random road
void Dynamite::draw(int roadLoation)
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
