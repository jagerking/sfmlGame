#include <SFML/Graphics.hpp>
#include "playerClass.hpp"
#include "platformClass.hpp"
#include <iostream>
using namespace sf;


int windowWidth = 1000;
int windowHeight = 1000;
int halfWinHeight = windowHeight/2;
int halfWinWidth = windowWidth/2;


int main()
{
	//this creates the main window
	RenderWindow app(VideoMode(windowWidth, windowHeight), "Home for a Hermit");
	
	//boolians controlling the player character controls
	bool playerUp, playerDown, playerLeft, playerRight = false;
	
	//playerclass use!
	playerClass playerObject;
	
	//Load fonts
	Font ubuntuFont;
	ubuntuFont.loadFromFile("res/fonts/Ubuntu-R.ttf");
	//create text samples
	Text helloText("Hello this is a sample text", ubuntuFont, 25);

	//load player texture
	Texture swordAndFireTexture;
	swordAndFireTexture.loadFromFile("res/gfx/swordandfire.png");
	Sprite swordAndFireSprite(swordAndFireTexture);

	//start the game loop!
	while(app.isOpen())
	{	
		//Process Events
		Event event;
		while(app.pollEvent(event))
		{	
			//Close The Window:Exit
			if(event.type == Event::Closed)
				app.close();
		}
		
		//keyboard input checks!
		//if the keys are being pressed!
		if(Keyboard::isKeyPressed(Keyboard::D)) 
			{
				playerRight = true;
			}
		if(Keyboard::isKeyPressed(Keyboard::A)) 
			{
				playerLeft = true;
			}
		if(Keyboard::isKeyPressed(Keyboard::S)) 
			{
				playerDown = true;
			}
		if(Keyboard::isKeyPressed(Keyboard::W)) 
			{
				playerUp = true;
			}
		
		//if the keys are NOT being pressed!
		if(!(Keyboard::isKeyPressed(Keyboard::D)))
			{
				playerRight = false;
			}
		if(!(Keyboard::isKeyPressed(Keyboard::A)))
			{
				playerLeft = false;
			}
		if(!(Keyboard::isKeyPressed(Keyboard::S))) 
			{
				playerDown = false;
			}
		if(!(Keyboard::isKeyPressed(Keyboard::W)))
			{
				playerUp = false;
			}

		playerObject.update(playerUp, playerDown, playerRight, playerLeft);
		playerObject.collide();

		//Clear the Screen before doing anything graphics : Initialize to zero
		app.clear();
		//draw sprite!
		app.draw(swordAndFireSprite);
		swordAndFireSprite.move(Vector2f(playerObject.xvel, playerObject.yvel));
//		app.draw(helloText);
		//Update the window
		app.display();
		
	}
	//Proper exit code for c++
	return 0;
}
