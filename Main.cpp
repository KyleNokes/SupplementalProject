//Kyle Nokes
//June 5 2014
//for Rob Robson

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
	SDL_Window* window = SDL_CreateWindow("My New Window", 100, 100, 800, 600, SDL_WINDOW_SHOWN); //make a new Window

	//Declare colours to make it easier
	SDL_Colour black = { 0, 0, 0 };
	SDL_Colour white = { 255, 255, 255 };
	SDL_Colour blue = { 0, 0, 255 };
	SDL_Colour red = { 255, 0, 0 };
	SDL_Colour green = { 0, 255, 0 };
	SDL_Colour yellow = { 255, 255, 0 };

	SDL_Colour* selectedColour = &white;

	Panel myPanel = Panel("mytexture.bmp", window); //Declare a Panel to hold the rest of the widgets
	Label myLabel = Label(0, 0, "Label with BMP background", "label.bmp", black, &myPanel); // Label with texture
	Label myOtherLabel = Label(0, 40, "Label with Transparent Background", black, &myPanel); // Label with no Background
	Label myThirdLabel = Label(500, 40, "Label with Coloured Background", blue, black, &myPanel); // Label with colour
	Button myButton = Button(50, 70,"Button with Texture", "uglyButton.bmp", black, &myPanel); //Button with Texture
	Button myOtherButton = Button(550, 100, "Button With Colour", green, white, &myPanel); //Button with colour
	RadioButtonGroup rad = RadioButtonGroup(5, 400, 325, &myPanel); //Group of 5 Radio Buttons
	RadioButtonGroup textAreaSelect = RadioButtonGroup(2, 0, 350, &myPanel); //Group of 4 Radio Buttons
	CheckBox box = CheckBox(400, 300, true, &myPanel, "Textured Background"); // Check Box
	TextArea textArea = TextArea(10, 400, 250, 100, black, &myPanel); // Multiline text area
	TextField field = TextField(10, 400, 250, black, &myPanel); //Single line Text field

	//changing the text attached to the radio buttons
	textAreaSelect.buttons[0]->label.labelText = "Multiline"; 
	textAreaSelect.buttons[1]->label.labelText = "Single Line";

	rad.buttons[0]->label.labelText = "Red";
	rad.buttons[1]->label.labelText = "Blue";
	rad.buttons[2]->label.labelText = "Green";
	rad.buttons[3]->label.labelText = "Yellow";
	rad.buttons[4]->label.labelText = "White";

	while (quit == false)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			box.Clicked(&event); //I could use this as a condition for the button to toggle, but I wanted it to be held down
			
			//Radio Buttons wait for input
			rad.HandleClick(&event);
			textAreaSelect.HandleClick(&event);

			if (box.selected) //If checkbox is selected...
			{
				//...allow the buttons to change panel texture
				if (myButton.MouseClicked(&event))
					myPanel.background = SDL_LoadBMP("otherText.bmp");

				if (myOtherButton.MouseClicked(&event))
					myPanel.background = SDL_LoadBMP("bestTexture.bmp");

				else if (!myButton.MouseClicked(&event) && !myOtherButton.MouseClicked(&event))
					myPanel.background = SDL_LoadBMP("mytexture.bmp");
			}
			else if (!box.selected) //if checkbox is not selected
			{
				//...allow radio buttons to change panel colour
				myPanel.background = SDL_GetWindowSurface(window);
				SDL_FillRect(myPanel.background, NULL, SDL_MapRGB(myPanel.background->format, selectedColour->r,
																							  selectedColour->g,
																							  selectedColour->b));
			}
			//these radio buttons
			if (rad.buttons[0]->selected)
				selectedColour = &red;
			else if (rad.buttons[1]->selected)
				selectedColour = &blue;
			else if (rad.buttons[2]->selected)
				selectedColour = &green;
			else if (rad.buttons[3]->selected)
				selectedColour = &yellow;
			else if (rad.buttons[4]->selected)
				selectedColour = &white;


			if (textAreaSelect.buttons[0]->selected)//if radio button 0 selected
			{
				//allow multiline editor only
				textArea.EditText(&event);
				textArea.Render();
			}
			else if (textAreaSelect.buttons[1]->selected)//if radio button 1 selected
			{
				//allow single line editor only
				field.EditText(&event);
				field.Render();
			}

			//Render everything on event
			myLabel.Render();
			myOtherLabel.Render();
			myThirdLabel.Render();
			myButton.Render();
			myOtherButton.Render();
			textAreaSelect.Render();
			box.Render();
			rad.Render();
			myPanel.Render();

			if (event.type == SDL_QUIT)
				quit = true;
		}
	}
	SDL_DestroyWindow(window);
	return 0;
}