#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include "RadioButton.h"

class RadioButtonGroup
{
public:
	int numButtons;
	std::vector <RadioButton*> buttons;
	RadioButtonGroup();
	~RadioButtonGroup();
	RadioButtonGroup(Uint32 _numButtons, int _x, int _y, Panel* _parent);
	void HandleClick(SDL_Event* event);
	void Render();
};