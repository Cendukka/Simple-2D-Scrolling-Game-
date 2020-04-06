/**
** File: Background1.h
** Author: Samuli Lehtonen
** Student ID: 301121118
** Last modified by Samuli
** Last modified: April 6th 2020
** Program description: Header file for the secoind scrolling background.
** Revision History: 1
*/
#pragma once
#ifndef __BACKGROUND1__
#define __BACKGROUND1__
#include "DisplayObject.h"
#include "Scene.h"

#include "DisplayObject.h"
#include "TextureManager.h"

class Background1 : public DisplayObject
{


public:
	Background1();
	~Background1();

	void draw() override;
	void update() override;
	void clean() override;

	int getFlowingSpeed();
	glm::vec2 getStartingPosition();

	void setStartingPosition(glm::vec2 startingPosition);
	void setFlowingSpeed(int speed);

private:

	int m_flowingSpeed;
	glm::vec2 m_startingPosition;
};

#endif /* Defined background1*/