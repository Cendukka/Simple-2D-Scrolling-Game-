#include "Background.h"
#include "Game.h"
#include "Level1Scene.h"

Background::Background()
{

	TheTextureManager::Instance()->load("../Assets/Background.png","level1Scene1", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene1");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5, Config::SCREEN_HEIGHT * 0.5));
	setType(GameObjectType::BACK_GROUND);

	setFlowingSpeed(2.0);
	setStartingPosition(glm::vec2(getPosition().x, getPosition().y + 25));
	
	
}

Background::~Background()
{
}

void Background::draw()
{
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene1");
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	
	TheTextureManager::Instance()->draw("level1Scene1", xComponent, yComponent, TheGame::Instance()->getRenderer(), 0, 255,true);
	


}
//update the background and scroll it down
void Background::update()
{
	//update the position of the background
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene1");
	glm::vec2 currentPositionTemp = getPosition();
	currentPositionTemp.y += getFlowingSpeed();
	setPosition(currentPositionTemp);
	//reset the background position if the current y position over the screen
	if(getPosition().y >=  size.y*1.5)
	{
		setPosition(glm::vec2(getStartingPosition().x , getStartingPosition().y - getHeight()));
	}
}

void Background::clean()
{
}

int Background::getFlowingSpeed()
{
	return m_flowingSpeed;
}

glm::vec2 Background::getStartingPosition()
{
	return m_startingPosition;
}

void Background::setStartingPosition(glm::vec2 startingPosition)
{
	m_startingPosition = startingPosition;
}

void Background::setFlowingSpeed(int speed)
{
	m_flowingSpeed = speed;
}
