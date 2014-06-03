#pragma once
#include <SDL.h>
#include "Panel.h"
#include "Label.h"
#ifndef CHECKBOX_H
#define	CHECKBOX_H

class CheckBox
{
public:
	bool selected;
	SDL_Rect position = SDL_Rect();
	Panel* parent;
	SDL_Surface* selTexture;
	SDL_Surface* desTexture;
	~CheckBox();
	explicit CheckBox();
	explicit CheckBox(int _x, int _y, bool _selected, Panel* _parent, const char* labelText);
	virtual bool Clicked(SDL_Event* event);
	void Render();

protected:
	Label label = Label();
	SDL_Colour black;
	SDL_Surface* background;
};
#endif // !CHECKBOX_H
