#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Scene.h"

// Game Objects
#include "Car.h"
#include "Label.h"

#include <memory>

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// Steering related functions
	glm::vec2 getTargetPosition();
	void setTargetPosition(glm::vec2 newPosition);




	glm::vec2 getGoalLocation();
	void setGoalLocation(glm::vec2 newLocation);
	bool findShortestPath();
	void resetClosedAndOpen();
private:
	// GameObjects
	Ship m_ship;
	Label* m_pLabel;

	// utility functions for ship control
	void m_createShips();
	void m_drawShips();
	void m_updateShips();
	void m_respawnShips();
	void m_moveShipsAlongPath();

	// utility functions for planet control
	void m_createPlanet();
	void m_respawnPlanet();

	// utility functions for mine control
	void m_createMines();
	void m_drawMines();
	void m_updateMines();
	void m_respawnMines();

	// Tile and Grid variables
	const int m_rowSize = Config::ROW_NUM;
	const int m_colSize = Config::COL_NUM;
	const int m_tileSize = Config::TILE_SIZE;

	Tile* m_grid[Config::COL_NUM ][Config::ROW_NUM]; 

	glm::vec2 m_goalLocation;
	bool m_moveAlongPath = false;
	int m_pathLength = 0;

	



	glm::vec2 m_mousePosition;

	// ImGui utility functions
	void m_ImGuiKeyMap();
	void m_ImGuiSetStyle();
	void m_updateUI();

	// ImGui menu variables
	bool m_exitApp = false;
	bool m_displayAbout = false;
	bool m_displayUI = true;
	
	void m_resetAll();

};

#endif /* defined (__PLAY_SCENE__) */