#pragma once
#include <SDL.h>
#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H
#include "CheckBox.h"

class RadioButton : public CheckBox
{
public:
	RadioButton() :CheckBox(){}
	RadioButton(int _x, int _y, bool _selected, Panel* _parent, const char* labelText) :CheckBox(_x, _y, _selected, _parent, labelText)
	{
		selTexture = SDL_LoadBMP("radSelect.bmp");
		desTexture = SDL_LoadBMP("radDesel.bmp");
	}

	virtual bool Clicked(SDL_Event* event);
};
#endif // !RADIOBUTTON_H
