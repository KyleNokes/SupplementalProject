#pragma once
#include <SDL.h>
#ifndef PANEL_H
#define PANEL_H

class Panel
{
public:
	SDL_Colour colour;
	SDL_Surface* background;
	SDL_Renderer* renderer;
	int width = 0;
	int height = 0;

	Panel();
	Panel(SDL_Colour _colour, SDL_Window* win);
	Panel(const char* _filename, SDL_Window* win);
	Panel(SDL_Surface _background, SDL_Window* win);
	~Panel();
	void AttachLabel();
	void Render();

private:
	SDL_Window* window;
	SDL_Texture* texture;
	void Initialize();
};

#endif //define PANEL_H