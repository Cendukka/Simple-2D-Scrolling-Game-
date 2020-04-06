#include "InstruScene.h"
#include "Game.h"
#include <iostream>
#include "Background.h"
#include "Background1.h"
#include "CollisionManager.h"
#include "ScoreBoardManager.h"
#include "MenuButton.h"

InstruScene::InstruScene()
{
	start();
}

InstruScene::~InstruScene()
{
}
//Draw the gameobjects for the scene
void InstruScene::draw()
{
	
	m_pBackground->draw();
	m_pBackground1->draw();
	m_pInstruTitleLabel->draw();
	m_pInstruContentLabel1->draw();
	m_pInstruContentLabel2->draw();
	m_pInstruContentLabel3->draw();
	m_pInstruContentLabel4->draw();
	m_pInstruContentLabel5->draw();
	m_pInstruContentLabel6->draw();
	m_pMenuButton->draw();
}
	


void InstruScene::update()
{
	
	m_pBackground->update();
	m_pBackground1->update();
	m_pMenuButton->setMousePosition(m_mousePosition);
	m_pMenuButton->ButtonClick();

}



void InstruScene::clean()
{
	delete m_pInstruTitleLabel;
	delete m_pInstruContentLabel1;
	delete m_pInstruContentLabel2;
	delete m_pInstruContentLabel3;
	delete m_pInstruContentLabel4;
	delete m_pInstruContentLabel5;
	delete m_pInstruContentLabel6;
	removeAllChildren();
}

void InstruScene::handleEvents()
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
				//check the button and register the click
				if (m_mouseRegister < 1) {
					m_mouseRegister = 1;
					m_pMenuButton->setMouseButtonClicked(true);
				}
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_mouseRegister = 0;
				m_pMenuButton->setMouseButtonClicked(false);
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

void InstruScene::start()
{
	// allocates memory on the heap for this game object


	m_pBackground = new Background();
	m_pBackground1 = new Background1();
	SDL_Color blue = { 0, 0, 255, 255 };
	m_pInstruTitleLabel = new Label("Instructions: ", "helsinki", 40, blue, glm::vec2(400.0f, 40.0f));
	m_pInstruContentLabel1 = new Label("You are the Cash Hunter \"blue\", collect cash and dodge the dynamites.", "helsinki", 20, blue, glm::vec2(400.0f, 150.0f));
	m_pInstruContentLabel2 = new Label("Collect either $50000 cash before the enemy hunter \"red\" or kill him", "helsinki", 20, blue, glm::vec2(400.0f, 175.0f));
	m_pInstruContentLabel3 = new Label("by leading him into dynamites. Don't let yourself hit dynamites, ", "helsinki", 20, blue, glm::vec2(400.0f, 200.0f));
	m_pInstruContentLabel4 = new Label("but let red one hit, the enemy. You control both.", "helsinki", 20, blue, glm::vec2(400.0f, 225.0f));
	m_pInstruContentLabel5 = new Label("Use 'A' to move left, and 'D' to move right.", "helsinki", 30, blue, glm::vec2(400.0f, 450.0f));
	m_pInstruContentLabel6 = new Label("Press 'Esc' to exit the game anytime", "helsinki", 30, blue, glm::vec2(400.0f, 500.0f));
	m_pMenuButton = new MenuButton();
	m_pMenuButton->setMouseButtonClicked(false);

	m_pMenuButton->setParent(this);
	m_pBackground->setParent(this);
	m_pBackground1->setParent(this);

	addChild(m_pMenuButton);
	addChild(m_pBackground);
	addChild(m_pBackground1);

}

glm::vec2 InstruScene::getMousePosition()
{
	return m_mousePosition;
}

