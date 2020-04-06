/**
** File: EndScene.h
** Author: Samuli Lehtonen
** Student ID: 301121118
** Last modified by Samuli
** Last modified: April 6th 2020
** Program description: Header file for the End Scene, the Game over screen of the game
** Revision History: 1
*/
#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Background.h"
#include "Background1.h"

class EndScene : public Scene
{
public:
	EndScene();
	~EndScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;


private:
	Label* m_LabelGameOver;
	Label* m_LabelNewGame;
	Label* m_LabelPlayerScore;
	Label* m_LabelEnemyScore;
	Label* m_LabelPlayerLife;
	Label* m_LabelEnemyLife;
	Background* m_pBackground;
	Background1* m_pBackground1;
};

#endif /* defined (__END_SCENE__) */