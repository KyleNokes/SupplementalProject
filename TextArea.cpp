#include "TextArea.h"

TextArea::~TextArea()
{
	SDL_StopTextInput();
	x, y, w, h = 0;
	text = "";
	parent = nullptr;
	font = nullptr;
}

TextArea::TextArea(int _x, int _y, int _w, int _h, SDL_Colour _txtColour, Panel* _parent)
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
	parent = _parent;
	txtColour = _txtColour;
	position->x = parent->width - (parent->width - x);
	position->y = parent->height - (parent->height - y);
	position->w = w;
	position->h = h;

	background->x = position->x;
	background->y = position->y;
	background->w = position->w;
	background->h = position->h;
	font = TTF_OpenFont("Arial.ttf", 20);
}

void TextArea::EditText(SDL_Event* event)
{
	if (MouseClicked(event))
	{
		SDL_StartTextInput();
		SDL_SetTextInputRect(background);
		switch (event->type)
		{
		default:
			SDL_StopTextInput();
			break;
		case SDL_TEXTEDITING:
			composition = event->edit.text;
			cursor = event->edit.start;
			selection = event->edit.length;
			break;
		case SDL_TEXTINPUT:
			text.append(event->text.text);
			break;
		case SDL_KEYDOWN:
			if (event->key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
				text.pop_back();
			if (event->key.keysym.sym == SDLK_RETURN)
				text.append("\n");
			break;
		}
	}

	else
	{
		SDL_StopTextInput();
	}
}

bool TextArea::MouseClicked(SDL_Event* event)
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
		if (!mouseInside && event->type == SDL_MOUSEBUTTONDOWN)
			isClicked = false;
	}

	return isClicked;
}

void TextArea::Render()
{
	const char* tmpText = text.c_str();
	message = TTF_RenderText_Blended_Wrapped(font, tmpText, txtColour, w);
	SDL_FillRect(parent->background, background, SDL_MapRGB(parent->background->format, 255, 255, 255));
	SDL_BlitSurface(message, NULL, parent->background, position);

	if (position->h > background->h)
		SDL_StopTextInput();
}