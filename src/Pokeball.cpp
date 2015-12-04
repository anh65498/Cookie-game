#include "Pokeball.h"

//#include <SFML/Graphics.hpp>


void updatePokeball(float &x, sf::Sprite &ball1Sprite, sf::Sprite &ball2Sprite, sf::Sprite &ball3Sprite)		//make pokeball wiggle
{
	x += 0.10;
	float angle = 10 * sin(x);
	ball1Sprite.setRotation(angle);
	ball2Sprite.setRotation(angle);
	ball3Sprite.setRotation(angle);
}
