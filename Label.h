#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "Panel.h"
#ifndef LABEL_H
#define LABEL_H

class Label
{
public:
	int x, y;
	SDL_Rect* position = new SDL_Rect;
	const char* labelText;
	SDL_Colour colour;
	SDL_Colour txtColour;
	SDL_Surface* background = nullptr;
	Panel* parent;

	explicit Label();
	~Label();
	Label (int _x, int _y, const char* _text, SDL_Colour _txtColour, Panel* parentPanel);
	explicit Label(int _x, int _y, const char* _text, SDL_Colour _bgColour, SDL_Colour _txtColour, Panel* parentPanel);
	explicit Label(int _x, int _y, const char* _text, const char* _filename, SDL_Colour _txtColour, Panel* parentPanel);
	explicit Label(int _x, int _y, const char* _text, SDL_Surface _background, SDL_Colour _txtColour, Panel* parentPanel);
	void Render();

private:
	bool coloured = false;
	SDL_Surface* message;
	SDL_Rect* txtPos = new SDL_Rect;
	TTF_Font* font = TTF_OpenFont("Arial.ttf", 20);
};
#endif //define LABEL_H