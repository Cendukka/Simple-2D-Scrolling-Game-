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