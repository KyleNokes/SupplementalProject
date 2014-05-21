#include <SDL.h>
#include "Label.h"
#include <iostream>

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Window* window = SDL_CreateWindow("My New Window", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Colour myCol = { 0, 0, 0 };
	SDL_Colour bgCol = { 255, 255, 255 };

	//Panel myPanel = Panel(myCol, window);
	Panel myPanel = Panel("mytexture.bmp", window);
	Label myLabel = Label("Testing Text", bgCol, myCol, &myPanel);

	return 0;
}
