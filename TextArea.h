#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Panel.h"

class TextArea
{
public:
	int x, y, w, h;
	Panel* parent;
	SDL_Rect* position = new SDL_Rect;
	SDL_Colour bgColour;
	SDL_Colour txtColour;
	std::string text = "Enter Text here";
	~TextArea();
	TextArea(int _x, int _y, int _w, int _h, SDL_Colour _txtColour, Panel* parentSurface);
	void EditText(SDL_Event* event);
	virtual void Render();

protected:
	SDL_Rect* background = new SDL_Rect;
	SDL_Surface* message;
	TTF_Font* font;
	char* composition;
	Sint32 cursor;
	Sint32 selection;

	bool isClicked = false;
	bool MouseClicked(SDL_Event* event);
};