
#include "Game.h"

MenuButton::MenuButton()
	// call super constructor
	:Button(
		"../Assets/MenuButton.png",
		"startButton",
		START_BUTTON, glm::vec2(400.0f, 350.0f)), m_isClicked(false)
{
	
}

MenuButton::~MenuButton()
{
}

bool MenuButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			std::cout << "Mouse Button Clicked!" << std::endl;
			TheSoundManager::Instance()->playSound("menu", 0);
			m_isClicked = true;
			TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


