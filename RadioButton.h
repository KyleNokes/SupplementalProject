#include <SDL.h>
#include "CheckBox.h"

class RadioButton : public CheckBox
{
public:
	RadioButton(int _x, int _y, bool _selected, Panel* _parent, const char* labelText) :CheckBox(_x, _y, _selected, _parent, labelText)
	{
		selTexture = SDL_LoadBMP("radSelect.bmp");
		desTexture = SDL_LoadBMP("radDesel.bmp");
	}
};