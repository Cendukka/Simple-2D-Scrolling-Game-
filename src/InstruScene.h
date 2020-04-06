#pragma once
#ifndef __INSTRU_LEVEL__
#define __INSTRU_LEVEL__

#include "Scene.h"
#include "Label.h"
#include "Background.h"
#include "Background1.h"
#include "MenuButton.h"



class InstruScene : public Scene
{
public:
	InstruScene();
	~InstruScene();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	static const int MAX_COMETS = 4;
	static const int MAX_SMALL_ENEMIES = 3;



	// getters
	glm::vec2 getMousePosition();


private:
	// game objects

	glm::vec2 m_mousePosition;

	int m_mouseRegister;
	Background* m_pBackground;
	Background1* m_pBackground1;
	Label* m_pInstruTitleLabel;
	//instruction labels
	Label* m_pInstruContentLabel1;
	Label* m_pInstruContentLabel2;
	Label* m_pInstruContentLabel3;
	Label* m_pInstruContentLabel4;
	Label* m_pInstruContentLabel5;
	Label* m_pInstruContentLabel6;
	//******************
	MenuButton* m_pMenuButton;
};

#endif /* defined (__INSTRU_LEVEL__) */
