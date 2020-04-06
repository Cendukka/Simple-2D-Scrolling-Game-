/**
** File: CashHunter1.h
** Author: Samuli Lehtonen
** Student ID: 301121118
** Last modified by Samuli
** Last modified: April 6th 2020
** Program description: Header file for the Player cash hunter, 
*** controlled  by the player, purpose is to collect cash and dodge dynamites
** Revision History: 1
*/
#pragma once
#ifndef __CASH_HUNTER1__
#define __CASH_HUNTER1__

#include <vector>

#include "DisplayObject.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "Scene.h"

class CashHunter1 :
	public DisplayObject
{
public:
	CashHunter1();
	~CashHunter1();

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


#endif /* defined (__CASH_HUNTER1__) */

