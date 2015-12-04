#include "Overlap.h"

//check if two sprites are colliding 

bool overlap(sf::Sprite& sprite1, sf::Sprite& sprite2)
{
	sf::FloatRect rectangle1 = sprite1.getGlobalBounds();		//get top left corner position and bottom right position 
	sf::FloatRect rectangle2 = sprite2.getGlobalBounds();

	return rectangle1.left <= (rectangle2.left + rectangle2.width) &&
		rectangle2.left <= (rectangle1.left + rectangle1.width) &&
		rectangle1.top <= (rectangle2.top + rectangle2.height) &&
		rectangle2.top <= (rectangle1.top + rectangle1.height);
}
