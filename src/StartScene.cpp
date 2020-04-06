#include "StartScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
{
}

void StartScene::draw()
{
	m_pBackground->draw();
	m_pBackground1->draw();
	m_pStartLabel->draw();
	m_pStartButton->draw();
	m_pExitButton->draw();
	m_pInstruButton->draw();
	
}

void StartScene::update()
{
	m_pBackground->update();
	m_pBackground1->update();
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
	m_pExitButton->setMousePosition(m_mousePosition);
	m_pExitButton->ButtonClick();
	m_pInstruButton->setMousePosition(m_mousePosition);
	m_pInstruButton->ButtonClick();
	
}

void StartScene::clean()
{
	delete m_pStartLabel;
	Mix_HaltMusic();
	removeAllChildren();
}

void StartScene::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;

			/*std::cout << "Mouse X: " << m_mousePosition.x << std::endl;
			std::cout << "Mouse Y: " << m_mousePosition.y << std::endl;
			std::cout << "---------------------------------------------" << std::endl;*/
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(true);
				m_pExitButton->setMouseButtonClicked(true);
				m_pInstruButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				m_pExitButton->setMouseButtonClicked(false);
				m_pInstruButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::INSTRU_SCENE);
				break;
			case SDLK_3:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			default:
				break;
			}
		}
	}
}

// this function is used for initialization
void StartScene::start()
{
	
	SDL_Color blue = { 0, 0, 255, 255 };
	m_pStartLabel = new Label("The Cash Hunt!", "helsinki", 40, blue, glm::vec2(400.0f, 40.0f));

	m_pStartButton = new StartButton();
	m_pExitButton = new ExitButton();
	m_pInstruButton = new InstruButton();

	m_pBackground = new Background();
	m_pBackground1 = new Background1();

	m_pStartButton->setMouseButtonClicked(false);
	m_pExitButton->setMouseButtonClicked(false);
	m_pInstruButton->setMouseButtonClicked(false);

	m_pStartButton->setParent(this);
	m_pExitButton->setParent(this);
	m_pInstruButton->setParent(this);
	m_pBackground->setParent(this);
	m_pBackground1->setParent(this);
	m_pStartLabel->setParent(this);

	addChild(m_pStartLabel);
	addChild(m_pStartButton);
	addChild(m_pExitButton);
	addChild(m_pInstruButton);
	addChild(m_pBackground);
	addChild(m_pBackground1);
	
	if (!TheSoundManager::Instance()->getSoundsLoaded()) {
		//Load sound files
		TheSoundManager::Instance()->load("../Assets/audio/theme.ogg", "theme", SOUND_MUSIC);		//Start scene background
		TheSoundManager::Instance()->load("../Assets/audio/Menu.mp3", "menu", SOUND_SFX);			//Menu button sounds
		TheSoundManager::Instance()->load("../Assets/audio/walk.ogg", "walk", SOUND_SFX);			//Walking sounds
		TheSoundManager::Instance()->load("../Assets/audio/run.ogg", "run", SOUND_SFX);				//running soinds
		TheSoundManager::Instance()->load("../Assets/audio/cash.wav", "cash", SOUND_SFX);			//collecting cash sound
		TheSoundManager::Instance()->load("../Assets/audio/explosion.wav", "explosion", SOUND_SFX);	//hitting dynamite sound
		TheSoundManager::Instance()->load("../Assets/audio/lost.wav", "lost", SOUND_SFX);			//losing sound
		TheSoundManager::Instance()->load("../Assets/audio/victory.wav", "victory", SOUND_SFX);		//winning sound

		TheSoundManager::Instance()->setSoundsLoaded(true);
	}

	//play the background music
	TheSoundManager::Instance()->playMusic("theme", -1);
}
