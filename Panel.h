#include <SDL.h>
#include "FlowManager.h"

class Panel
{
public:
	SDL_Colour colour;
	SDL_Surface* background;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int width = 0;
	int height = 0;

	Panel();
	Panel(SDL_Colour _colour, SDL_Window* win);
	Panel(const char* _filename, SDL_Window* win);
	Panel(SDL_Surface _background, SDL_Window* win);
	~Panel();
	void AttachWidget(SDL_Surface widget);

private:
	FlowManager flow();
	SDL_Texture* texture;

	void Initialize();
};