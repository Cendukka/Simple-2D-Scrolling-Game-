
#include "Game.h"

InstruButton::InstruButton()
	// call super constructor
	:Button(
		"../Assets/InstruButton.png",
		"instruButton",
		INSTRU_BUTTON, glm::vec2(400.0f, 370.0f)), m_isClicked(false)
{
	
}

InstruButton::~InstruButton()
{
}

bool InstruButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			std::cout << "Mouse Button Clicked!" << std::endl;
			TheSoundManager::Instance()->playSound("menu", 0);
			m_isClicked = true;
			TheGame::Instance()->changeSceneState(SceneState::INSTRU_SCENE);
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


