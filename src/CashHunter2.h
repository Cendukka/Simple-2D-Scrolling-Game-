/**
** File: CashHunter2.h
** Author: Samuli Lehtonen
** Student ID: 301121118
** Last modified by Samuli
** Last modified: April 6th 2020
** Program description: Header file for the Enemy cash hunter,
*** controlled also by the player but purpose is to kill him or prevent him to collect cash
** Revision History: 1
*/
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

	

	//health
	int m_health;
	
	int m_currentRoad;

	

};


#endif /* defined (__CASH_HUNTER2__) */

