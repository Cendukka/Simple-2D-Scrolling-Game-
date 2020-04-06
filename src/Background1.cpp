#include "Background1.h"
#include "Game.h"
#include "Level1Scene.h"

Background1::Background1()
{

	


	TheTextureManager::Instance()->load("../Assets/Background.png", "level1Scene2", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene2");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH*0.5, (Config::SCREEN_HEIGHT * 0.5) - getHeight()));
	setType(GameObjectType::BACK_GROUND);

	setFlowingSpeed(2.0);
	setStartingPosition(glm::vec2(getPosition().x, getPosition().y + 25));

	
}

Background1::~Background1()
{
}

void Background1::draw()
{
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene2");
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("level1Scene2", xComponent, yComponent, TheGame::Instance()->getRenderer(), 0, 255, true);



}
//update the background and scroll it down
void Background1::update()
{
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene2");
	//update the current position of the background
	glm::vec2 currentPositionTemp = getPosition();
	currentPositionTemp.y += getFlowingSpeed();
	setPosition(currentPositionTemp);
	//reset the background position if the current y position over the screen
	if (getPosition().y >= size.y * 1.5)
	{
		setPosition(getStartingPosition());
	}
}

void Background1::clean()
{
}

int Background1::getFlowingSpeed()
{
	return m_flowingSpeed;
}

glm::vec2 Background1::getStartingPosition()
{
	return m_startingPosition;
}

void Background1::setStartingPosition(glm::vec2 startingPosition)
{
	m_startingPosition = startingPosition;
}

void Background1::setFlowingSpeed(int speed)
{
	m_flowingSpeed = speed;
}
