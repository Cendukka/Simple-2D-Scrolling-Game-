/**
** File: MenuButton.h
** Author: Samuli Lehtonen
** Student ID: 301121118
** Last modified by Samuli
** Last modified: April 6th 2020
** Program description: Header file for the Menu button, 
*** the button that will change scene from instruction scene to menu scene
** Revision History: 1
*/
#pragma once
#ifndef __MENU_BUTTON__
#define __MENU_BUTTON__

#include "Button.h"

class MenuButton : public Button
{
public:
	MenuButton();
	~MenuButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__MENU_BUTTON__) */