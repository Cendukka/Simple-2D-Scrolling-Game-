/**
** File: InstruButton.h
** Author: Samuli Lehtonen
** Student ID: 301121118
** Last modified by Samuli
** Last modified: April 6th 2020
** Program description: Header file for the Instru button, the button that will change scene from menu to instruction scene
** Revision History: 1
*/
#pragma once
#ifndef __INSTRU_BUTTON__
#define __INSTRU_BUTTON__

#include "Button.h"

class InstruButton : public Button
{
public:
	InstruButton();
	~InstruButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__INSTRU_BUTTON__) */