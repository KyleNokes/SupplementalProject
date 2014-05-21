#include "Label.h"
#include <iostream>

Label::Label()
{
}

Label::~Label()
{
}

Label::Label(const char* _text, SDL_Color _colour, SDL_Colour _txtColour, Panel* parentSurface)
{
	parent = parentSurface;
	colour = _colour;
	labelText = _text;
	txtColour = _txtColour;
	message = TTF_RenderText(font, labelText, txtColour, colour);
}

Label::Label(const char* _text, const char* _filename, SDL_Colour _txtColour, Panel* parentSurface)
{
	parent = parentSurface;
	background = SDL_LoadBMP(_filename);
	labelText = _text;
	txtColour = _txtColour;
	message = TTF_RenderText_Blended(font, labelText, txtColour);
	SDL_BlitSurface(message, NULL, background, NULL);
}
Label::Label(const char* _text, SDL_Surface _background, SDL_Colour _txtColour, Panel* parentSurface)
{
	parent = parentSurface;
	background = &_background;
	labelText = _text;
	txtColour = _txtColour;
	message = TTF_RenderText_Blended(font, labelText, txtColour);
	SDL_BlitSurface(message, NULL, background, NULL);
}
void Label::Initialize()
{
	renderer = parent->renderer;
	TTF_Init();
	font = TTF_OpenFont("Arial.ttf", 20);
	texture = SDL_CreateTextureFromSurface(renderer, background);
	SDL_FreeSurface(background);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	SDL_Delay(2000);
}
