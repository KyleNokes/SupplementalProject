#include "TextField.h"

TextField::~TextField()
{
	SDL_StopTextInput();
	x, y, w, h = 0;
	text = "";
	parent = nullptr;
	font = nullptr;
}

void TextField::Render()
{
	const char* tmpText = text.c_str();
	message = TTF_RenderText_Blended(font, tmpText, txtColour);
	SDL_FillRect(parent->background, background, SDL_MapRGB(parent->background->format, 255, 255, 255));
	SDL_BlitSurface(message, NULL, parent->background, position);

	if (position->w >= background->w)
		SDL_StopTextInput();
}