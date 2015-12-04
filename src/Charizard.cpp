#include "Charizard.h"


void charizardMove(sf::Sprite &charizardSprite, sf::Vector2f &charizardPosition)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		charizardSprite.move(0, -5);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		charizardSprite.move(0, 5);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		charizardSprite.move(-5, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		charizardSprite.move(5, 0);


	charizardPosition = charizardSprite.getPosition();

	//Prevent Charizard from going out of the screen
	if (charizardPosition.x <= 0)
	{
		charizardSprite.setPosition(charizardPosition.x + 10, charizardPosition.y);
	}
	else if (charizardPosition.x >= 800)
	{
		charizardSprite.setPosition(charizardPosition.x - 10, charizardPosition.y);
	}
	if (charizardPosition.y <= 0)
	{
		charizardSprite.setPosition(charizardPosition.x, charizardPosition.y + 10);
	}
	else if (charizardPosition.y >= 600)
	{
		charizardSprite.setPosition(charizardPosition.x, charizardPosition.y - 10);
	}
	//End of preventing Charizard from going out of screen

}