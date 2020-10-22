#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class playerClass
{
public:
	float xvel;
	float yvel;
	float xpos;
	float ypos;
	bool playerFaceRight;
	bool onGround;
	bool playerUp;
	playerClass()
	{
		playerFaceRight = true;
		xpos = 0;
		ypos = 0;
		xvel = 0;
		yvel = 0;
		onGround = false;
	}
	void update(bool playerUp, bool playerDown, bool playerRight, bool playerLeft)
	{
		//update for directional velocity change
		if(playerRight == true)
		{
			xvel = 1;
			playerFaceRight = true;
		}
		if(playerLeft == true)
		{
			xvel = -1;
			playerFaceRight = false;
		}
		if(playerDown == true)
		{
			yvel = 1;
		}
		if(playerUp == true)
		{
			yvel = -1;
		}
		if(!(playerRight == true || playerLeft == true))
		{
			xvel = 0;
		}
		if(!(playerUp == true || playerDown == true))
		{
			yvel = 0;
		}
		if(onGround == true)
		{
			yvel = 0;
		}
		if(!onGround == false && playerUp == true)
		{
			yvel = -1;
		}
		xpos += xvel;
		ypos += yvel;
		collide();
		std::cout << onGround << std::endl;

	}
	void collide()
	{
		if(ypos > 500 || ypos < 0)
		{
			onGround = true;
		}
		else
		{
			onGround = false;
		}
	}
};