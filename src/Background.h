#pragma once
#ifndef __BACKGROUND__
#define __BACKGROUND__
#include "DisplayObject.h"
#include "Scene.h"

#include "DisplayObject.h"
#include "TextureManager.h"

class Background : public DisplayObject
{


public:
	Background();
	~Background();
	
	void draw() override;
	void update() override;
	void clean() override;

	int getFlowingSpeed();
	glm::vec2 getStartingPosition();

	void setStartingPosition(glm::vec2 startingPosition);
	void setFlowingSpeed(int speed);
	
private:

	int m_flowingSpeed;
	glm::vec2 m_startingPosition;
};

#endif /* Defined background*/