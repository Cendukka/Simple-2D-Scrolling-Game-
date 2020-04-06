#pragma once
#ifndef __SCORE_BOARD_MANAGER__
#define __SCORE_BOARD_MANAGER__

#include "Config.h"
#include "Label.h"

class ScoreBoardManager
{
public:
	// singleton
	static ScoreBoardManager* Instance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new ScoreBoardManager();
			return m_pInstance;
		}
		return m_pInstance;
	}

	void Start();
	void Draw() const;

	// getters and setters
	int getPlayerScore() const;
	void setPlayerScore(int new_score);
	int getEnemyScore() const;
	void setEnemyScore(int new_score);

	int getPlayerHealth() const;
	void setPlayerHealth(int new_health);
	int getEnemyHealth() const;
	void setEnemyHealth(int new_health);

private:
	ScoreBoardManager();
	~ScoreBoardManager();

	int m_playerScore{};
	int m_enemyScore{};
	int m_playerHealth{};
	int m_enemyHealth{};
	int m_powerUp{};

	Label* m_pPlayerHealthLabel{};
	Label* m_pEnemyHealthLabel{};
	Label* m_pPlayerScoreLabel{};
	Label* m_pEnemyScoreLabel{};

	static ScoreBoardManager* m_pInstance;

	int m_enemiesLeft;
};
#endif /* defined (__SCORE_BOARD_MANAGER__) */