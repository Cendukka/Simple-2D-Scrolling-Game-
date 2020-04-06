#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>
#include "ScoreBoardManager.h"

EndScene::EndScene()
{
	EndScene::start();
}

EndScene::~EndScene()
{
}

void EndScene::draw()
{
	m_pBackground->draw();
	m_pBackground1->draw();
	m_LabelGameOver->draw();
	m_LabelNewGame->draw();
	m_LabelPlayerScore->draw();
	m_LabelEnemyScore->draw();
	m_LabelPlayerLife->draw();
	m_LabelEnemyLife->draw();
}

void EndScene::update()
{
	m_pBackground->update();
	m_pBackground1->update();
}

void EndScene::clean()
{
	delete m_LabelGameOver;
	delete m_LabelNewGame;
	delete m_LabelPlayerScore;
	delete m_LabelEnemyScore;
	delete m_LabelPlayerLife;
	delete m_LabelEnemyLife;
	Mix_HaltMusic();
	removeAllChildren();
}

void EndScene::handleEvents()
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

void EndScene::start()
{
	int theScore = ScoreBoardManager::Instance()->getPlayerScore();
	int theEvilScore = ScoreBoardManager::Instance()->getEnemyScore();
	int theLifes = ScoreBoardManager::Instance()->getPlayerHealth();
	int theEvilLifes = ScoreBoardManager::Instance()->getEnemyHealth();
	
	SDL_Color blue = { 0, 0, 255, 255 };
	SDL_Color red = { 255, 0, 0, 255 };
	m_LabelGameOver = new Label("GAME OVER", "helsinki", 80, red, glm::vec2(400.0f, 40.0f));
	m_LabelNewGame = new Label("Press \"1\" to Start again!", "helsinki", 30, blue, glm::vec2(400.0f, 160.0f));
	m_LabelPlayerScore = new Label("Your score was: " + std::to_string(theScore), "helsinki", 30, blue, glm::vec2(400.0f, 250.0f));
	m_LabelEnemyScore = new Label("Enemy score was: " + std::to_string(theEvilScore), "helsinki", 30, blue, glm::vec2(400.0f, 300.0f));
	m_LabelPlayerLife = new Label("Your lifes: " + std::to_string(theLifes), "helsinki", 30, blue, glm::vec2(400.0f, 350.0f));
	m_LabelEnemyLife = new Label("Enemy's lifes: " + std::to_string(theEvilLifes), "helsinki", 30, blue, glm::vec2(400.0f, 400.0f));

	m_LabelGameOver->setParent(this);
	m_LabelNewGame->setParent(this);
	m_LabelPlayerScore->setParent(this);
	m_LabelEnemyScore->setParent(this);
	m_LabelPlayerLife->setParent(this);
	m_LabelEnemyLife->setParent(this);

	addChild(m_LabelGameOver);
	addChild(m_LabelNewGame);
	addChild(m_LabelPlayerScore);
	addChild(m_LabelEnemyScore);
	addChild(m_LabelPlayerLife);
	addChild(m_LabelEnemyLife);

	m_pBackground = new Background();
	m_pBackground1 = new Background1();
	
	addChild(m_pBackground);
	addChild(m_pBackground1);

	
	
	//play the music
	TheSoundManager::Instance()->playSound("lost", 0);
}