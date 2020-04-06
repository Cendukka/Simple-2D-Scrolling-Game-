#include "CashHunter2.h"
#include "Game.h"
#include "Util.h"
#include "GLM/gtx/rotate_vector.hpp"
#include "Level1Scene.h"
#include "GLM/gtx/string_cast.hpp"
#include "ScoreBoardManager.h"
#include "RoadLocation.h"


CashHunter2::CashHunter2()
{
	TheTextureManager::Instance()->load("../Assets/CashHunter2.png",
		"CashHunter2", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("CashHunter2");

	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(400.0f, 500.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setType(GameObjectType::ENEMY);
	setCurrentRoad(RoadLocation::ROAD_MIDDLE);

	m_health = 70;
}


CashHunter2::~CashHunter2()
{
}

void CashHunter2::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("CashHunter2", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);

}



void CashHunter2::update()
{
	//setPosition(getPosition());
	//setPowerUp(ScoreBoardManager::Instance()->getPowerUp());
}




void CashHunter2::clean()
{

}
//Handle the movement of enemy to the right
void CashHunter2::moveRight()
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
//Handle the movement of enemy to the left
void CashHunter2::moveLeft()
{
	int currentRoad = getCurrentRoad();

	if (currentRoad != ROAD_LEFT) {
		//check the current road and change the road to the next on the Left
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

int CashHunter2::getCurrentRoad()
{
	return m_currentRoad;
}

void CashHunter2::setCurrentRoad(int currentRoad)
{
	m_currentRoad = currentRoad;
}





//decrease life when hit on dynamite and check the life at the same time, if 0, show win scene
void CashHunter2::decreaseLife()
{
	m_health -= 1;

	if (m_health <= 0)
	{
		TheGame::Instance()->changeSceneState(SceneState::WIN_SCENE);
	}
}