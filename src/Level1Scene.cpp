#include "Level1Scene.h"
#include "Game.h"
#include <iostream>
#include "Background.h"
#include "Background1.h"
#include "CollisionManager.h"
#include "ScoreBoardManager.h"
#include "RoadLocation.h"


Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	//draws game objects
	m_pBackground->draw();
	m_pBackground->draw();
	m_pBackground1->draw();
	m_pCashHunter1->draw();
	m_pCashHunter2->draw();
	for (int i = 0; i < MAX_DYNAMITE; i++) {
		m_pDynamites[i]->draw();
	}
	for (int i = 0; i < MAX_CASH; i++) {
		m_pCashes[i]->draw();
	}
	ScoreBoardManager::Instance()->Draw();
	
}

void Level1Scene::update()
{

	if (ScoreBoardManager::Instance()->getPlayerScore() >= 50000)
	{
		
		TheGame::Instance()->changeSceneState(SceneState::WIN_SCENE);
	}
	if (ScoreBoardManager::Instance()->getEnemyScore() >= 50000)
	{

		TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
	}
	//update car
	m_pCashHunter1->update();
	m_pCashHunter2->update();
	//update
	for (int i = 0; i < MAX_DYNAMITE; i++) {
		m_pDynamites[i]->update();
	}
	for (int i = 0; i < MAX_CASH; i++) {
		m_pCashes[i]->update();
	}

	for (int i = 0; i < MAX_DYNAMITE; i++)
	{
		if (Collision::squaredRadiusCheck(m_pCashHunter1, m_pDynamites[i]))
		{
			m_pCashHunter1->decreaseLife();
		}
		if (Collision::squaredRadiusCheck(m_pCashHunter2, m_pDynamites[i]))
		{
			m_pCashHunter2->decreaseLife();
		}
	}
	for (int i = 0; i < MAX_CASH; i++)
	{
		Collision::squaredRadiusCheck(m_pCashHunter1, m_pCashes[i]);
		Collision::squaredRadiusCheck(m_pCashHunter2, m_pCashes[i]);
	}
	
	m_pBackground->update();
	m_pBackground1->update();
	
	raiseTempo(ScoreBoardManager::Instance()->getPlayerScore());
	raiseTempo(ScoreBoardManager::Instance()->getEnemyScore());
}



void Level1Scene::clean()
{
	
	Mix_HaltChannel(-1);
	removeAllChildren();
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				

				if (m_mouseRegister < 1) {
					
					m_mouseRegister = 1;
				}
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				
				m_mouseRegister = 0;
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
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
			case SDLK_w:

				break;
			case SDLK_s:

				break;
			case SDLK_a:
				m_pCashHunter1->moveLeft();
				m_pCashHunter2->moveRight();
				break;
			case SDLK_d:
				m_pCashHunter1->moveRight();
				m_pCashHunter2->moveLeft();
				break;
			}

			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:

				break;

			case SDLK_s:

				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}

			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	// allocates memory

	m_pBackground = new Background();
	m_pBackground1 = new Background1();
	m_pCashHunter1 = new CashHunter1();
	m_pCashHunter2 = new CashHunter2();
	for (int i = 0; i < MAX_DYNAMITE; i++) {
		m_pDynamites[i] = new Dynamite(i);
		m_pDynamites[i] ->setParent(this);
		addChild(m_pDynamites[i]);
	}
	for (int i = 0; i < MAX_CASH; i++) {
		m_pCashes[i] = new Cash(i);
		m_pCashes[i]->setParent(this);
		addChild(m_pCashes[i]);
	}
	ScoreBoardManager::Instance()->Start();
	ScoreBoardManager::Instance()->setPlayerScore(0);
	ScoreBoardManager::Instance()->setEnemyScore(0);
	ScoreBoardManager::Instance()->setPlayerHealth(Config::PLAYER_HEALTH);
	ScoreBoardManager::Instance()->setEnemyHealth(Config::ENEMY_HEALTH);

	//play the walk sound
	TheSoundManager::Instance()->playSound("walk", -1);

	m_pBackground->setParent(this);
	m_pBackground1->setParent(this);
	m_pCashHunter1->setParent(this);
	m_pCashHunter2->setParent(this);

	addChild(m_pBackground);
	addChild(m_pBackground1);
	addChild(m_pCashHunter1);
	addChild(m_pCashHunter2);
}

void Level1Scene::raiseTempo(int playerEnemyScore)
{
	
	switch (playerEnemyScore)
	{
	case 5000:
		if (m_pBackground->getFlowingSpeed() < 3) {
			for (int i = 0; i < MAX_DYNAMITE; i++) {
				m_pDynamites[i]->setMovingSpeed(m_pDynamites[i]->getMovingSpeed() + 1);
			}
			for (int i = 0; i < MAX_CASH; i++) {
				m_pCashes[i]->setMovingSpeed(m_pCashes[i]->getMovingSpeed() + 1);
			}
			m_pBackground->setFlowingSpeed(m_pBackground->getFlowingSpeed() + 1);
			m_pBackground1->setFlowingSpeed(m_pBackground1->getFlowingSpeed() + 1);
		
		}
		break;
	case 10000:
		if (m_pBackground->getFlowingSpeed() < 4) {
			for (int i = 0; i < MAX_DYNAMITE; i++) {
				m_pDynamites[i]->setMovingSpeed(m_pDynamites[i]->getMovingSpeed() + 1);
			}
			for (int i = 0; i < MAX_CASH; i++) {
				m_pCashes[i]->setMovingSpeed(m_pCashes[i]->getMovingSpeed() + 1);
			}
			m_pBackground->setFlowingSpeed(m_pBackground->getFlowingSpeed() + 1);
			m_pBackground1->setFlowingSpeed(m_pBackground1->getFlowingSpeed() + 1);
		
		}
		break;
	case 20000:
		if (m_pBackground->getFlowingSpeed() < 5) {
			for (int i = 0; i < MAX_DYNAMITE; i++) {
				m_pDynamites[i]->setMovingSpeed(m_pDynamites[i]->getMovingSpeed() + 1);
			}
			for (int i = 0; i < MAX_CASH; i++) {
				m_pCashes[i]->setMovingSpeed(m_pCashes[i]->getMovingSpeed() + 1);
			}
			m_pBackground->setFlowingSpeed(m_pBackground->getFlowingSpeed() + 1);
			m_pBackground1->setFlowingSpeed(m_pBackground1->getFlowingSpeed() + 1);
			
		}
		break;
	case 25000:
		if (m_pBackground->getFlowingSpeed() < 6) {
			for (int i = 0; i < MAX_DYNAMITE; i++) {
				m_pDynamites[i]->setMovingSpeed(m_pDynamites[i]->getMovingSpeed() + 1);
			}
			for (int i = 0; i < MAX_CASH; i++) {
				m_pCashes[i]->setMovingSpeed(m_pCashes[i]->getMovingSpeed() + 1);
			}
			m_pBackground->setFlowingSpeed(m_pBackground->getFlowingSpeed() + 1);
			m_pBackground1->setFlowingSpeed(m_pBackground1->getFlowingSpeed() + 1);
			//Set running sound
			Mix_HaltChannel(-1);
			TheSoundManager::Instance()->playSound("run", -1);
		}

			break;
	case 35000:
		if (m_pBackground->getFlowingSpeed() < 7) {
			for (int i = 0; i < MAX_DYNAMITE; i++) {
				m_pDynamites[i]->setMovingSpeed(m_pDynamites[i]->getMovingSpeed() + 1);
			}
			for (int i = 0; i < MAX_CASH; i++) {
				m_pCashes[i]->setMovingSpeed(m_pCashes[i]->getMovingSpeed() + 1);
			}
			m_pBackground->setFlowingSpeed(m_pBackground->getFlowingSpeed() + 1);
			m_pBackground1->setFlowingSpeed(m_pBackground1->getFlowingSpeed() + 1);

			
		}
		break;
	case 40000:
		if (m_pBackground->getFlowingSpeed() < 8) {
			for (int i = 0; i < MAX_DYNAMITE; i++) {
				m_pDynamites[i]->setMovingSpeed(m_pDynamites[i]->getMovingSpeed() + 1);
			}
			for (int i = 0; i < MAX_CASH; i++) {
				m_pCashes[i]->setMovingSpeed(m_pCashes[i]->getMovingSpeed() + 1);
			}
			m_pBackground->setFlowingSpeed(m_pBackground->getFlowingSpeed() + 1);
			m_pBackground1->setFlowingSpeed(m_pBackground1->getFlowingSpeed() + 1);
		}
		break;
	default:
		break;
	}
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

