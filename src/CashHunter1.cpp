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
	m_powerUp = 0;
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
	//setPosition(getPosition());
	//setPowerUp(ScoreBoardManager::Instance()->getPowerUp());
}




void CashHunter1::clean()
{
	
}

void CashHunter1::moveRight()
{
	int currentRoad = getCurrentRoad();

	if (currentRoad != ROAD_RIGHT) {
		
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

void CashHunter1::moveLeft()
{
	int currentRoad = getCurrentRoad();

	if (currentRoad != ROAD_LEFT) {

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



void CashHunter1::setPowerUp(int value)
{
	m_powerUp = value;
}

//decrease life when hit on comet and check the life at the same time
void CashHunter1::decreaseLife()
{
	m_health -= 1;

	if(m_health <= 0)
	{
		TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
	}
}


void CashHunter1::m_checkBounds()
{

	if (getPosition().x > Config::SCREEN_WIDTH)
	{
		setPosition(glm::vec2(0.0f, getPosition().y));
	}

	if (getPosition().x < 0)
	{
		setPosition(glm::vec2(800.0f, getPosition().y));
	}

	if (getPosition().y > Config::SCREEN_HEIGHT)
	{
		setPosition(glm::vec2(getPosition().x, 0.0f));
	}

	if (getPosition().y < 0)
	{
		setPosition(glm::vec2(getPosition().x, 600.0f));
	}

}

void CashHunter1::m_reset()
{
	setIsColliding(false);
	int halfWidth = getWidth() * 0.5;
	int xComponent = rand() % (640 - getWidth()) + halfWidth + 1;
	int yComponent = -getHeight();
	setPosition(glm::vec2(xComponent, yComponent));
}
