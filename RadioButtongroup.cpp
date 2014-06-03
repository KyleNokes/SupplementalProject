#include "RadioButtonGroup.h"

RadioButtonGroup::RadioButtonGroup()
{}

RadioButtonGroup::~RadioButtonGroup()
{
	for (int i = 0; i < numButtons; i++)
	{
		buttons[i]->~RadioButton();
	}
	buttons.clear();
}

RadioButtonGroup::RadioButtonGroup(Uint32 _numButtons, int _x, int _y, Panel* _parent)
{
	numButtons = _numButtons;
	buttons.push_back (new RadioButton(_x, _y, true, _parent, "Radio Button"));

	for (int i = 1; i < numButtons; i++)
	{
		int newY = buttons[i - 1]->position.y + buttons[0]->position.h + 20;
		buttons.push_back(new RadioButton(_x, newY, false, _parent, "Radio Button"));
	}
}

void RadioButtonGroup::HandleClick(SDL_Event* event)
{
	for (int i = 0; i < numButtons; i++)
	{
		if (buttons[i]->Clicked(event))
		{
			for (int j = 0; j < numButtons; j++)
			{
				if (i != j && buttons[j]->selected)
					buttons[j]->selected = false;
			}
		}
	}
}

void RadioButtonGroup::Render()
{
	for (int i = 0; i < numButtons; i++)
	{
		buttons[i]->Render();
	}
}