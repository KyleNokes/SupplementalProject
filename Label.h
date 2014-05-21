#include <SDL.h>
#include <SDL_ttf.h>
#include "Panel.h"

class Label
{
public:
	const char* labelText;
	SDL_Colour colour;
	SDL_Colour txtColour;
	SDL_Surface* background;
	Panel* parent;

	Label();
	~Label();
	Label(const char* _text, SDL_Colour _bgColour, SDL_Colour _txtColour, Panel* parentSurface);
	Label(const char* _text, const char* _filename, SDL_Colour _txtColour, Panel* parentSurface);
	Label(const char* _text, SDL_Surface _background, SDL_Colour _txtColour, Panel* parentSurface);

private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Surface* message;
	TTF_Font* font;
	void Initialize();
};