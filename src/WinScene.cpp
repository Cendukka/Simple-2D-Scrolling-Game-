#include "WinScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>
#include "ScoreBoardManager.h"

WinScene::WinScene()
{
	WinScene::start();
}

WinScene::~WinScene()
{
}
//Draw the gameobjects for the scene
void WinScene::draw()
{
	m_pBackground->draw();
	m_pBackground1->draw();
	m_LabelWin->draw();
	m_LabelNewGame->draw();
	m_LabelPlayerScore->draw();
	m_LabelEnemyScore->draw();
}

void WinScene::update()
{
	m_pBackground->update();
	m_pBackground1->update();
}

void WinScene::clean()
{
	delete m_LabelWin;
	delete m_LabelNewGame;
	delete m_LabelPlayerScore;
	delete m_LabelEnemyScore;
	removeAllChildren();
}

void WinScene::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			}
			break;
		default:
			break;
		}
	}
}

void WinScene::start()
{
	int theScore = ScoreBoardManager::Instance()->getPlayerScore();
	int theEvilScore = ScoreBoardManager::Instance()->getEnemyScore();
	
	SDL_Color blue = { 0, 0, 255, 255 };
	SDL_Color red = { 255, 0, 0, 255 };
	m_LabelWin = new Label("YOU WON! GZ!", "helsinki", 80, blue, glm::vec2(400.0f, 40.0f));
	m_LabelNewGame = new Label("Press \"1\" to Start again!", "helsinki", 30, red, glm::vec2(400.0f, 160.0f));
	m_LabelPlayerScore = new Label("Your score was: " + std::to_string(theScore), "helsinki", 30, red, glm::vec2(400.0f, 250.0f));
	m_LabelEnemyScore = new Label("Enemy score was " + std::to_string(theEvilScore), "helsinki", 30, red, glm::vec2(400.0f, 300.0f));

	m_LabelWin->setParent(this);
	m_LabelNewGame->setParent(this);
	m_LabelPlayerScore->setParent(this);
	m_LabelEnemyScore->setParent(this);

	addChild(m_LabelWin);
	addChild(m_LabelNewGame);
	addChild(m_LabelPlayerScore);
	addChild(m_LabelEnemyScore);

	m_pBackground = new Background();
	m_pBackground1 = new Background1();
	
	addChild(m_pBackground);
	addChild(m_pBackground1);
}