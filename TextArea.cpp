#include "TextArea.h"

TextArea::TextArea(int _x, int _y, int _w, int _h)
{
	TTF_Init();
	font = TTF_OpenFont("Arial.ttf", 20);

	w = _w;
	h = _h;
	x = _x;
	y = _y;

	SDL_SetTextInputRect(this);
}

void TextArea::EditText()
{
	SDL_StartTextInput();

}