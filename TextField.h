#include <SDL.h>
#include "TextArea.h"

class TextField : public TextArea
{
public:
	TextField();
	TextField(int _x, int _y, int _w, SDL_Colour _txtColour, Panel* parentSurface) :TextArea(_x, _y, _w, 20, _txtColour, parentSurface){}
	virtual void Render();
};

void TextField::Render()
{
	const char* tmpText = text.c_str();
	message = TTF_RenderText_Blended(font, tmpText, txtColour);
	SDL_FillRect(parent->background, background, SDL_MapRGB(parent->background->format, 255, 255, 255));
	SDL_BlitSurface(message, NULL, parent->background, position);

	if (position->w >= background->w)
		SDL_StopTextInput();
}