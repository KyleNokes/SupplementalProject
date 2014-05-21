#include <SDL.h>
#include <SDL_ttf.h>

class TextArea : SDL_Rect
{
public:
	int x, y;
	TextArea(int _x, int _y, int _w, int _h);
	void EditText();
private:
	SDL_Colour textColour;
	TTF_Font* font;
};