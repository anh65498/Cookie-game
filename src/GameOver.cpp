#include "GameOver.h"

//#include "ResourcePath.h"				Note: can't open resourcePath here but can in main.cpp

#include <string>
#include <sstream>

using namespace std;

void drawGameOverText(sf::RenderWindow &window, int score)			//draw Game Over screen
{
	sf::Font Font;
	Font.loadFromFile("../../assets/MilasianCircaThinPERSONAL.ttf");

	sf::Font FontArial;
	FontArial.loadFromFile("../../assets/arial.ttf");

	sf::Text textGO;
	textGO.setFont(Font);
	textGO.setString("Game Over");
	textGO.setPosition(220, 150);
	textGO.setCharacterSize(100);
	textGO.setColor(sf::Color::Red);
	textGO.setStyle(sf::Text::Bold);


	sf::Text textHS;
	textHS.setFont(FontArial);
	textHS.setString("High Score:");
	textHS.setPosition(500, 100);
	textHS.setCharacterSize(35);
	textHS.setColor(sf::Color::Magenta);
	textHS.setStyle(sf::Text::Bold);


	sf::Text finalScore;
	finalScore.setFont(FontArial);
	finalScore.setString(to_string(score));
	finalScore.setPosition(750, 100);
	finalScore.setCharacterSize(35);
	finalScore.setColor(sf::Color::Magenta);
	finalScore.setStyle(sf::Text::Bold);


	sf::Text reset;
	reset.setFont(Font);
	reset.setString("Press 'A' to play again");
	reset.setPosition(225, 450);
	reset.setCharacterSize(50);
	reset.setColor(sf::Color::White);
	reset.setStyle(sf::Text::Italic);

	window.clear();						//clear every pixel on the screen 
	window.draw(textGO);
	window.draw(reset);
	window.draw(finalScore);
	window.draw(textHS);
	window.display();
}