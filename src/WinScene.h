/**
** File: WinScene.h
** Author: Samuli Lehtonen
** Student ID: 301121118
** Last modified by Samuli
** Last modified: April 6th 2020
** Program description: Header file for the Win Scene, the winning screen of the game
** Revision History: 1
*/
#pragma once
#ifndef __WIN_SCENE__
#define __WIN_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Background.h"
#include "Background1.h"

class WinScene : public Scene
{
public:
	WinScene();
	~WinScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;


private:
	Label* m_LabelWin;
	Label* m_LabelNewGame;
	Label* m_LabelPlayerScore;
	Label* m_LabelEnemyScore;
	Background* m_pBackground;
	Background1* m_pBackground1;
};

#endif /* defined (__WIN_SCENE__) */