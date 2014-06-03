#pragma once
#include <SDL.h>
#include <array>
#include "RadioButton.h"

class RadioButtonGroup
{
public:
	int numButtons;
	RadioButton* buttons[1];
	RadioButtonGroup();
	~RadioButtonGroup();
	RadioButtonGroup(int _numButtons, int _x, int _y, Panel* _parent);
	void HandleClick(SDL_Event* event);
	void Render();
};