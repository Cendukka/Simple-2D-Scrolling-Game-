
#include "Game.h"

ExitButton::ExitButton()
	// call super constructor
	:Button(
		"../Assets/ExitButton.png",
		"exitButton",
		EXIT_BUTTON, glm::vec2(125.0f, 545.0f)), m_isClicked(false)
{
	
}

ExitButton::~ExitButton()
{
}

bool ExitButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			std::cout << "Mouse Button Clicked!" << std::endl;
			TheSoundManager::Instance()->playSound("menu", 0);
			m_isClicked = true;
			TheGame::Instance()->quit();
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


