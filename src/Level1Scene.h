#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"

#include "CashHunter1.h"
#include "CashHunter2.h"
#include "Dynamite.h"
#include "Cash.h"
#include "Background.h"
#include "Background1.h"
#include "Label.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	static const int MAX_DYNAMITE = 4;
	static const int MAX_CASH = 3;
	//Raise the game speed
	void raiseTempo(int playerEnemyScore);


	

	// getters
	glm::vec2 getMousePosition();
	

private:
	// game objects

	glm::vec2 m_mousePosition;

	int m_mouseRegister;
	CashHunter1* m_pCashHunter1;
	CashHunter2* m_pCashHunter2;
	Dynamite* m_pDynamites[MAX_DYNAMITE];
	Cash* m_pCashes[MAX_CASH];
	Background* m_pBackground;
	Background1* m_pBackground1;
	Label* m_pLabel;
};

#endif /* defined (__LEVEL_1_SCENE__) */
