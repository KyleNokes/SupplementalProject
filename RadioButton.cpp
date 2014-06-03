#include "RadioButton.h"

RadioButton::~RadioButton()
{
	label.~Label();
	parent = nullptr;
}

bool RadioButton::Clicked(SDL_Event* event)
{
	if (event->type == SDL_MOUSEMOTION || SDL_MOUSEBUTTONDOWN || SDL_MOUSEBUTTONUP)
	{
		int mouseX, mouseY;
		bool mouseInside = true;
		SDL_GetMouseState(&mouseX, &mouseY);

		if (mouseX < position.x)
			mouseInside = false;
		else if (mouseY < position.y)
			mouseInside = false;
		else if (mouseX > position.x + background->w)
			mouseInside = false;
		else if (mouseY > position.y + background->h)
			mouseInside = false;

		if (mouseInside && !selected && event->type == SDL_MOUSEBUTTONUP)
		{
			selected = true;
		}
	}

	return selected;
}