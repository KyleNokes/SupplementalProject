#include <SDL.h>
#include <vector>

class FlowManager : SDL_Rect
{
public:
	FlowManager(int width, int height);
	void AddWidget(SDL_Surface widget, int index);
	void RemoveWidget(int index);
	void ManageFlow();

	std::vector<SDL_Rect> widgets;
};