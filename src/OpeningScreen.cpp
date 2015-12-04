#include "OpeningScreen.h"
#include "HowTo.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

using namespace std;


void openingScreen(sf::RenderWindow &window, int &LIVES, GAME_STATE &state)
{
	sf::Font font;
	font.loadFromFile(resourcePath() + "assets/MilasianCircaThinPERSONAL.ttf");

	sf::Text openingText;
	openingText.setFont(font);
	openingText.setString("Welcome to the cookie game");
	openingText.setCharacterSize(100);
	openingText.setColor(sf::Color::White);
	openingText.setPosition(100, 200);
	openingText.setStyle(sf::Text::Bold);
	openingText.setStyle(sf::Text::Italic);
	openingText.setStyle(sf::Text::Underlined);

	sf::Text startGame;
	startGame.setFont(font);
	startGame.setString("Press S to start ");
	startGame.setCharacterSize(80);
	startGame.setColor(sf::Color::White);
	startGame.setPosition(300, 450);
	startGame.setStyle(sf::Text::Bold);
	startGame.setStyle(sf::Text::Italic);
	startGame.setStyle(sf::Text::Underlined);
	
	//window.clear();
	window.draw(startGame);
	window.draw(openingText);
	window.display();

	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		state = HOWTO_SCREEN; 
		cout << "\nIs Opening screen checking keypressed";
	}
	

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Unknown))
	{
		//window.clear();
	}
	*/
	
}
