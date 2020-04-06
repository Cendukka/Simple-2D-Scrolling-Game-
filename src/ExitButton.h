/**
** File: ExitButton.h
** Author: Samuli Lehtonen
** Student ID: 301121118
** Last modified by Samuli
** Last modified: April 6th 2020
** Program description: Header file for the Exit button, the button that will quit the game
** Revision History: 1
*/
#pragma once
#ifndef __EXIT_BUTTON__
#define __EXIT_BUTTON__

#include "Button.h"

class ExitButton : public Button
{
public:
	ExitButton();
	~ExitButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__EXIT_BUTTON__) */