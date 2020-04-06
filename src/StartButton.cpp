
#include "Game.h"

StartButton::StartButton()
	// call super constructor
	:Button(
		"../Assets/StartButton.png",
		"startButton",
		START_BUTTON, glm::vec2(400.0f, 200.0f)), m_isClicked(false)
{
	
}

StartButton::~StartButton()
{
}

bool StartButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			std::cout << "Mouse Button Clicked!" << std::endl;
			m_isClicked = true;
			TheSoundManager::Instance()->playSound("engine", 0);
			TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


