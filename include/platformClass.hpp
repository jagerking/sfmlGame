#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class platformClass
{
public:
	float xpos;
	float ypos;
	float xvel;
	float yvel;
	platformClass(float xpos, float ypos)
	{
		xpos = xpos;
		ypos = ypos;
	}
};