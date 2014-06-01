#include "Label.h"

class Button : public Label
{
public:
	Button() :Label(){}
	Button(int _x, int _y, const char* _text, SDL_Colour _bgColour, SDL_Colour _txtColour, Panel* parentSurface) : Label(_x, _y, _text, _bgColour, _txtColour, parentSurface) {}
	Button(int _x, int _y, const char* _text, const char* _filename, SDL_Colour _txtColour, Panel* parentSurface) : Label(_x, _y, _text, _filename, _txtColour, parentSurface){}
	Button(int _x, int _y, const char* _text, SDL_Surface _background, SDL_Colour _txtColour, Panel* parentSurface) : Label(_x, _y, _text, _background, _txtColour, parentSurface){}
	bool isClicked = false;
	bool MouseClicked(SDL_Event* event);
};

bool Button::MouseClicked(SDL_Event* event)
{
	if (event->type == SDL_MOUSEMOTION || SDL_MOUSEBUTTONDOWN || SDL_MOUSEBUTTONUP)
	{
		int mouseX, mouseY;
		bool mouseInside = true;
		SDL_GetMouseState(&mouseX, &mouseY);

		if (mouseX < x)
			mouseInside = false;
		else if (mouseY < y)
			mouseInside = false;
		else if (mouseX > x + background->w)
			mouseInside = false;
		else if (mouseY > y + background->h)
			mouseInside = false;

		if (mouseInside && event->type == SDL_MOUSEBUTTONDOWN)
			isClicked = true;
		if (event->type == SDL_MOUSEBUTTONUP)
			isClicked = false;
	}

	return isClicked;
}