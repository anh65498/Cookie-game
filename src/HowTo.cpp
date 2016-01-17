#include "HowTo.h"

void HowToScreen(sf::RenderWindow& window, GAME_STATE &state, int &LIVES)
{
	/*
	sf::Font font;
	font.loadFromFile(resourcePath() + "assets/MilasianCircaThinPERSONAL.ttf");

	sf::Text openingText;
	openingText.setFont(font);
	openingText.setString("Welcome to the cookie game");
	openingText.setCharacterSize(100);
	openingText.setColor(sf::Color::White);
	*/
	
	sf::Font font; 
	font.loadFromFile(resourcePath() + "assets/MilasianCircaThinPERSONAL.ttf");

	sf::Text Title;
	Title.setFont(font);
	Title.setString("How To play this game");
	Title.setCharacterSize(100);
	Title.setStyle(sf::Text::Bold);
	Title.setColor(sf::Color::Blue);
	Title.setPosition(200, 100 );

	sf::Text instruction1 ("Use arrow key (Up, Down, Left, Right) to move", font);
	instruction1.setCharacterSize(50);
	instruction1.setColor(sf::Color::White);
	instruction1.setPosition(200, 250);
	
	sf::Text instruction2("Press SpaceBar to defend from Cookie ", font);
	instruction2.setCharacterSize(50);
	instruction2.setColor(sf::Color::White);
	instruction2.setPosition(200, 300);

	sf::Text instruction3("Dodge the fireball and the cookie", font);
	instruction3.setCharacterSize(50);
	instruction3.setColor(sf::Color::White);
	instruction3.setPosition(200, 350);

	sf::Text ready("Are you ready? Press B to start", font);
	ready.setCharacterSize(80);
	ready.setColor(sf::Color::Green);
	ready.setPosition(150, 450);

	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		LIVES = 3;
		state = DURING_GAME;
	}
	else
	{ }
	*/

	window.clear();
	window.draw(Title);
	window.draw(instruction1);
	window.draw(instruction2);
	window.draw(instruction3);
	window.draw(ready);
	window.display();


}

