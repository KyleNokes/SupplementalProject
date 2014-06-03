#include <SDL.h>
#include "TextArea.h"

class TextField : public TextArea
{
public:
	TextField();
	~TextField();
	TextField(int _x, int _y, int _w, SDL_Colour _txtColour, Panel* parentSurface) :TextArea(_x, _y, _w, 20, _txtColour, parentSurface){}
	virtual void Render();
};