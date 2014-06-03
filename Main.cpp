#include <SDL.h>
#include <iostream>
#include "Button.h"
#include "TextArea.h"
#include "CheckBox.h"
#include "RadioButtonGroup.h"
#include "TextField.h"

int main(int argc, char** argv)
{
	SDL_Event event;
	bool quit = false;
	TTF_Init();
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Window* window = SDL_CreateWindow("My New Window", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Colour black = { 0, 0, 0 };
	SDL_Colour white = { 255, 255, 255 };
	SDL_Colour blue = { 0, 0, 255 };
	SDL_Colour red = { 255, 0, 0 };
	SDL_Colour green = { 0, 255, 0 };
	SDL_Colour yellow = { 255, 255, 0 };

	//Panel myPanel = Panel(black, window);
	Panel myPanel = Panel("mytexture.bmp", window);
	Label myLabel = Label(0, 0, "Label Text", "label.bmp", black, &myPanel);
	//Label myLabel = Label(0, 0, "Blarg, and also Honk", black, &myPanel);
	//Label myLabel = Label(0, 0, "Default text is default", blue, black, &myPanel);
	Button myButton = Button(50, 50,"Button", "uglyButton.bmp", black, &myPanel);
	//Button myButton = Button(50, 50, "Text on Button", green, white, &myPanel);
	TextArea textArea = TextArea(200, 200, 200, 100, black, &myPanel);
	CheckBox box = CheckBox(400, 300, true, &myPanel, "This are checkbox");
	RadioButton rad = RadioButton(400, 325, false, &myPanel, "Radio Button");
	//RadioButtonGroup rad = RadioButtonGroup(5, 400, 325, &myPanel);
	TextField field = TextField(10, 500, 150, black, &myPanel);

	while (quit == false)
	{
		while (SDL_PollEvent(&event))
		{
			textArea.EditText(&event);
			field.EditText(&event);
			box.Clicked(&event);
			rad.Clicked(&event);
			//rad.HandleClick(&event);

			if (myButton.MouseClicked(&event))
			{
				myPanel.background = SDL_LoadBMP("otherText.bmp");
				myLabel.Render();
				myButton.Render();
				textArea.Render();
				box.Render();
				myPanel.Render();
			}

			if (!myButton.MouseClicked(&event))
			{
				myPanel.background = SDL_LoadBMP("mytexture.bmp");
				myLabel.Render();
				myButton.Render();
				textArea.Render();
				box.Render();
				//rad.Render();
				field.Render();

				myPanel.Render();
			}

			if (event.type == SDL_QUIT)
				quit = true;
		}
	}
	return 0;
}
