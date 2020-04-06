#include "ScoreBoardManager.h"
#include "Game.h"

ScoreBoardManager* ScoreBoardManager::m_pInstance = nullptr;

void ScoreBoardManager::Start()
{
	const SDL_Color blue = { 0, 0, 255, 255 };
	const SDL_Color red = { 255, 0, 0, 255 };
	m_pPlayerHealthLabel = new Label("Player Lives: 3", "helsinki", 30, blue,
		glm::vec2(10.0f, 10.0f), TTF_STYLE_NORMAL, false);

	m_pEnemyHealthLabel = new Label("Enemy Lives: 50", "helsinki", 30, red,
		glm::vec2(10.0f, 90.0f), TTF_STYLE_NORMAL, false);
	
	m_pPlayerScoreLabel = new Label("Player Cash: 0", "helsinki", 30, blue,
		glm::vec2(10.0f, 50.0f), TTF_STYLE_NORMAL, false);
	m_pEnemyScoreLabel = new Label("Enemy Cash: 0", "helsinki", 30, red,
		glm::vec2(10.0f, 130.0f), TTF_STYLE_NORMAL, false);
}

void ScoreBoardManager::Draw() const
{
	m_pPlayerHealthLabel->draw();
	m_pEnemyHealthLabel->draw();
	m_pPlayerScoreLabel->draw();
	m_pEnemyScoreLabel->draw();
}

int ScoreBoardManager::getPlayerScore() const
{
	return m_playerScore;
}

void ScoreBoardManager::setPlayerScore(const int new_score)
{
	m_playerScore = new_score;
	m_pPlayerScoreLabel->setText("Player Cash: " + std::to_string(getPlayerScore()));
}
int ScoreBoardManager::getEnemyScore() const
{
	return m_enemyScore;
}

void ScoreBoardManager::setEnemyScore(const int new_score)
{
	m_enemyScore = new_score;
	m_pEnemyScoreLabel->setText("Enemy Cash: " + std::to_string(getEnemyScore()));
}

int ScoreBoardManager::getPlayerHealth() const
{
	return m_playerHealth;
}


void ScoreBoardManager::setPlayerHealth(const int new_lives)
{
	m_playerHealth = new_lives;
	if (m_playerHealth <= 0)
	{
		Game::Instance()->changeSceneState(END_SCENE);
	}
	m_pPlayerHealthLabel->setText("Lives: " + std::to_string(getPlayerHealth()));
}
int ScoreBoardManager::getEnemyHealth() const
{
	return m_enemyHealth;
}


void ScoreBoardManager::setEnemyHealth(const int new_lives)
{
	m_enemyHealth = new_lives;
	if (m_enemyHealth <= 0)
	{
		if (getEnemyScore() >= getPlayerScore()) {
			Game::Instance()->changeSceneState(END_SCENE);
		}
		else {
			Game::Instance()->changeSceneState(WIN_SCENE);
		}
		
	}
	m_pEnemyHealthLabel->setText("Lives: " + std::to_string(getEnemyHealth()));
}

ScoreBoardManager::ScoreBoardManager()
{
	Start();
	/*setScore(Config::SCORE);
	setHealth(Config::HEALTH);*/
}

ScoreBoardManager::~ScoreBoardManager()
= default;
