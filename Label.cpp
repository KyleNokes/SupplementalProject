#include "Label.h"
#include <iostream>

Label::Label()
{
}

Label::~Label()
{
	x, y = 0;
	parent = nullptr;
	labelText = NULL;
}

//Coloured text with transparent background
Label::Label(int _x, int _y, const char* _text, SDL_Colour _txtColour, Panel* _parent)
{
	x = _x;
	y = _y;
	parent = _parent;
	labelText = _text;
	txtColour = _txtColour;
	background = TTF_RenderText_Blended(font, labelText, txtColour);
	coloured = true;
}

//Coloured text with Coloured background
Label::Label(int _x, int _y, const char* _text, SDL_Color _colour, SDL_Colour _txtColour, Panel* _parent)
{
	x = _x;
	y = _y;
	parent = _parent;
	colour = _colour;
	labelText = _text;
	txtColour = _txtColour;
	background = TTF_RenderText(font, labelText, txtColour, colour);
	coloured = true;
}

Label::Label(int _x, int _y, const char* _text, const char* _filename, SDL_Colour _txtColour, Panel* _parent)
{
	x = _x;
	y = _y;
	parent = _parent;
	background = SDL_LoadBMP(_filename);
	labelText = _text;
	txtColour = _txtColour;
}
Label::Label(int _x, int _y, const char* _text, SDL_Surface _background, SDL_Colour _txtColour, Panel* _parent)
{
	x = _x;
	y = _y;
	parent = _parent;
	background = &_background;
	labelText = _text;
	txtColour = _txtColour;
}
void Label::Render()
{
	position->x = parent->width - (parent->width - x);
	position->y = parent->height - (parent->height - y);
	if (!coloured)
	{
		message = TTF_RenderText_Blended(font, labelText, txtColour);
		txtPos->x = background->clip_rect.x + (background->w / 2) - message->clip_rect.w / 2;
		txtPos->y = background->clip_rect.y + (background->h / 2) - message->clip_rect.h / 2;
		SDL_BlitSurface(message, NULL, background, txtPos);
	}
	SDL_BlitSurface(background, NULL, parent->background, position);
}
