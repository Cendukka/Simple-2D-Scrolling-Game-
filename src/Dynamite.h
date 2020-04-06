#pragma once
#ifndef __DYNAMITE__
#define __DYNAMITE__
#include "DisplayObject.h"
#include <SDL_hints.h>


class Dynamite : public DisplayObject
{
public:
	Dynamite(int selectedRoad);
	~Dynamite();
	
	void draw() override;
	void update() override;
	void clean() override;

	void draw(int roadLocation);
	void setActive(bool active);
	void setAlpha(Uint8 value);
	bool isActive();
	
	//get and set the current road
	int getCurrentRoad();
	void setCurrentRoad(int currentRoad);
	
	int getMovingSpeed();

	void setMovingSpeed(float newMovingSpeed);
	
	
private:
	std::string m_name;
	bool m_isCentered;
	bool m_isActive;
	Uint8 m_alpha;
	//the current road
	int m_currentRoad;
	float m_movingSpeed;
};


#endif
