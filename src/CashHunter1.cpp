#include "CashHunter1.h"
#include "Game.h"
#include "Util.h"
#include "GLM/gtx/rotate_vector.hpp"
#include "Level1Scene.h"
#include "GLM/gtx/string_cast.hpp"
#include "ScoreBoardManager.h"
#include "RoadLocation.h"


CashHunter1::CashHunter1()
{
	TheTextureManager::Instance()->load("../Assets/CashHunter1.png",
		"CashHunter1", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("CashHunter1");
	
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(400.0f, 400.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setType(GameObjectType::PLAYER);
	setCurrentRoad(RoadLocation::ROAD_MIDDLE);

	m_health = 3;
}


CashHunter1::~CashHunter1()
{
}

void CashHunter1::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("CashHunter1", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255,true );
	
}



void CashHunter1::update()
{
}

void CashHunter1::clean()
{
}

//Handle the movement of player the right
void CashHunter1::moveRight()
{
	int currentRoad = getCurrentRoad();

	if (currentRoad != ROAD_RIGHT) {
		//check the current road and change the road to the next on the right
		switch (currentRoad)
		{
		case ROAD_LEFT:
			setCurrentRoad(ROAD_MIDDLE_LEFT);
			setPosition(glm::vec2((getPosition().x + 160.0), getPosition().y));
			break;
		case ROAD_MIDDLE_LEFT:
			setCurrentRoad(ROAD_MIDDLE);
			setPosition(glm::vec2((getPosition().x + 160.0), getPosition().y));
			break;
		case ROAD_MIDDLE:
			setCurrentRoad(ROAD_MIDDLE_RIGHT);
			setPosition(glm::vec2((getPosition().x + 160.0), getPosition().y));
			break;
		case ROAD_MIDDLE_RIGHT:
			setCurrentRoad(ROAD_RIGHT);
			setPosition(glm::vec2((getPosition().x + 160.0), getPosition().y));
			break;
		
		default:
			break;
		}

	}
	
}
//Handle the movement of player and enemy to the left
void CashHunter1::moveLeft()
{
	int currentRoad = getCurrentRoad();

	if (currentRoad != ROAD_LEFT) {
		//check the current road and change the road to the next on the right
		switch (currentRoad)
		{
		case ROAD_MIDDLE_LEFT:
			setCurrentRoad(ROAD_LEFT);
			setPosition(glm::vec2((getPosition().x - 160.0), getPosition().y));
			break;
		case ROAD_MIDDLE:
			setCurrentRoad(ROAD_MIDDLE_LEFT);
			setPosition(glm::vec2((getPosition().x - 160.0), getPosition().y));
			break;
		case ROAD_MIDDLE_RIGHT:
			setCurrentRoad(ROAD_MIDDLE);
			setPosition(glm::vec2((getPosition().x - 160.0), getPosition().y));
			break;
		case ROAD_RIGHT:
			setCurrentRoad(ROAD_MIDDLE_RIGHT);
			setPosition(glm::vec2((getPosition().x - 160.0), getPosition().y));
			break;

		default:
			break;
		}
	}
}

int CashHunter1::getCurrentRoad()
{
	return m_currentRoad;
}

void CashHunter1::setCurrentRoad(int currentRoad)
{
	m_currentRoad = currentRoad;
}





//decrease life when hit on dynamite and check the life at the same time, if zero, end the game
void CashHunter1::decreaseLife()
{
	m_health -= 1;

	if(m_health <= 0)
	{
		TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
	}
}

