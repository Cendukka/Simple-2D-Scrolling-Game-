#pragma once
#ifndef __CASH_HUNTER2__
#define __CASH_HUNTER2__

#include <vector>

#include "DisplayObject.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "Scene.h"

class CashHunter2 :
	public DisplayObject
{
public:
	CashHunter2();
	~CashHunter2();

	// Inherited via GameObject
	void draw() override;

	void update() override;

	void clean() override;
	//moving functions
	void moveRight();
	void moveLeft();
	//get and set the current road
	int getCurrentRoad();
	void setCurrentRoad(int currentRoad);


	void setPowerUp(int value);
	void decreaseLife();
private:

	
	void m_checkBounds();

	void m_reset();

	//health
	int m_health;
	int m_powerUp;
	
	int m_currentRoad;

	

};


#endif /* defined (__CASH_HUNTER2__) */

