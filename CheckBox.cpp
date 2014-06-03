#include "CheckBox.h"

CheckBox::CheckBox()
{}

CheckBox::CheckBox(int _x, int _y, bool _selected, Panel* _parent, const char* labelText)
{
	selected = _selected;
	parent = _parent;
	position.x = parent->width - (parent->width - _x);
	position.y = parent->height - (parent->height - _y);
	black = { 0, 0, 0 };
	label = Label(position.x + selTexture->w, position.y, labelText, black, parent);
}

bool CheckBox::Clicked(SDL_Event* event)
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
		else if (mouseInside && selected && event->type == SDL_MOUSEBUTTONUP)
		{
			selected = false;
		}
	}

	return selected;
}

void CheckBox::Render()
{
	if (selected)
		background = selTexture;
	if (!selected)
		background = desTexture;

	SDL_BlitSurface(background, NULL, parent->background, &position);
	label.Render();
}