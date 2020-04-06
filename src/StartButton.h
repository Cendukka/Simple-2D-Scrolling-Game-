/**
** File: StartButton.h
** Author: Samuli Lehtonen
** Student ID: 301121118
** Last modified by Samuli
** Last modified: April 6th 2020
** Program description: Header file for the Start button, the button that will change scene from menu to playscene
** Revision History: 1
*/
#pragma once
#ifndef __START_BUTTON__
#define __START_BUTTON__

#include "Button.h"

class StartButton : public Button
{
public:
	StartButton();
	~StartButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__START_BUTTON__) */