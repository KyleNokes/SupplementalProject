#include "Panel.h"

Panel::Panel()
{
}

Panel::Panel(SDL_Colour _colour, SDL_Window* win)
{
	colour = _colour;
	window = win;
	coloured = true;
	SDL_GetWindowSize(window, &width, &height);
	Initialize();
}

Panel::Panel(const char* _filename, SDL_Window* win)
{
	window = win;
	background = SDL_LoadBMP(_filename);
	Initialize();
}

Panel::Panel(SDL_Surface _background, SDL_Window* win)
{
	window = win;
	background = &_background;
	Initialize();
}

Panel::~Panel()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_free(window);
	SDL_free(background);
	colour.r, colour.g, colour.b, colour.a, width, height = NULL;
	SDL_free(this);
}

void Panel::Initialize()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Panel::Render()
{
	if (coloured)
	{
		background = SDL_GetWindowSurface(window);
		SDL_FillRect(SDL_GetWindowSurface(window), NULL, SDL_MapRGB(background->format, colour.r, colour.g, colour.b));
	}

	if (!coloured)
	{

	}

	texture = SDL_CreateTextureFromSurface(renderer, background);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}