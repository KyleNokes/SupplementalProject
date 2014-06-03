#include "Panel.h"

Panel::Panel()
{
}

Panel::Panel(SDL_Colour _colour, SDL_Window* win)
{
	colour = _colour;
	window = win;
	SDL_GetWindowSize(window, &width, &height);
	background = SDL_GetWindowSurface(window);
	SDL_FillRect(SDL_GetWindowSurface(window), NULL, SDL_MapRGB(background->format, colour.r, colour.g, colour.b));
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
	background = nullptr;
	colour.r, colour.g, colour.b, colour.a, width, height = NULL;
	SDL_free(this);
}

void Panel::Initialize()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Panel::Render()
{
	texture = SDL_CreateTextureFromSurface(renderer, background);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}