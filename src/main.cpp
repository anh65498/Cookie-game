#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>

#include "main.h"					//contain prototype of enum GAME_STATE, so when file compile, they have prototype in  -> link all file 
#include "ResourcePath.h"
#include "Overlap.h"
#include "OpeningScreen.h"
#include "HowTo.h"
#include "Event.h"
#include "Pokeball.h"
#include "Charizard.h"
#include "GameOver.h"


using namespace std;				//don't need to write std:: anymore
									/** I changed the original size of the window from 800,600 to 1000, 800 */

void resetCookie(sf::Sprite &cookieSprite, int numOfCookie);

void update(sf::Sprite& charizardSprite, sf::Sprite &dgSprite, sf::RenderWindow &window, sf::Event &event, vector<sf::Sprite> &vectorDg, int &numOfDg,
					int &score, vector<sf::Sprite> &vectorCookie, int numOfCookie, vector<sf::Sprite> &vectorFire, int numFire, int &LIVES) 
{
	//move cookie and reset position
	for (int counter = 0; counter < numOfCookie; counter++)
	{
		vectorCookie[counter].move(-5, 0);
		sf::Vector2f position;
		position = vectorCookie[counter].getPosition();
		
		//cout << "The position of cookie " << counter + 1 << " : " << position.x << "         " << position.y <<endl;
		
		if (position.x < -50)
		{
			vectorCookie[counter].setPosition(700, rand() % 500);
		}
	
	}

	//Move fire and reset position
	for (int count = 0; count < numFire; count++)
	{
		vectorFire[count].move(0, 5);
		sf::Vector2f posFire;
		posFire = vectorFire[count].getPosition();
				
		//cout << "The position of Fire " << count + 1 << " : " << posFire.x << "         " << posPitchfork.y << endl;
		if (posFire.y > 600)
		{
			vectorFire[count].setPosition(rand() % 800, 0);
		}
	}
		//check if any fire collide (2 images on top of each other), then regenerate new pitchfork at new location
	
	
	
	//Move charizard
	sf::Vector2f charizardPosition;
	charizardMove(charizardSprite, charizardPosition);								//inside Charizard.h

																		
	//DG shooting
	window.setKeyRepeatEnabled(false);

	while (window.pollEvent(event)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			numOfDg++;
			vectorDg.push_back(dgSprite);
			vectorDg[numOfDg].setOrigin((charizardPosition.x) + 32.0, (charizardPosition.y) + 32.0);
			vectorDg[numOfDg].setPosition((charizardPosition.x) + 32.0, (charizardPosition.y) + 32.0);
		}	
	}


	for (int counter = 0; counter < vectorDg.size(); counter++)
		vectorDg[counter].move(5, 0); 
	
	//if CookieSprite overlap with dgSprite, reset position of cookieSprite
	for (int i = 0; i < vectorCookie.size(); i++)
	{
		for (int counter = 0; counter < vectorDg.size(); counter++)
		{
			if (overlap(vectorDg[counter], vectorCookie[i]))
			{
				vectorCookie[i].setPosition(700, rand() % 500);
				score++;
			}
		}
	}

	//if fireball overlap with Charizard, reset fireball
	for (int count = 0; count < numFire; count++)
	{
		if (overlap(vectorFire[count], charizardSprite))
		{
			vectorFire[count].setPosition(rand() % (LENGTHWINDOW - 100), 100);
			LIVES -= 1;
		}
	}
}

void draw(sf::RenderWindow& window, sf::Sprite& charizardSprite, vector<sf::Sprite> &vectorDg,
		sf::Sprite &ball1Sprite, sf::Sprite &ball2Sprite, sf::Sprite &ball3Sprite, int LIVES, vector<sf::Sprite> &vectorCookie, 
		vector<sf::Sprite> &vectorFire, int numFire)
{
	window.clear();	//set screen to black
	
	for (size_t counter = 0; counter < vectorCookie.size(); counter++)
	{
		window.draw(vectorCookie[counter]);
	}

	for (size_t counter = 0; counter < vectorFire.size(); counter++)
	{
		window.draw(vectorFire[counter]);
	}

	for (size_t counter = 0; counter < vectorDg.size(); counter++)
	{
		window.draw(vectorDg[counter]);
	}

	if (LIVES == 3)
	{
		window.draw(ball1Sprite);
		window.draw(ball2Sprite);
		window.draw(ball3Sprite);
	}

	else if (LIVES == 2)
	{
		window.draw(ball1Sprite);
		window.draw(ball2Sprite);
	}
	else if (LIVES == 1)
		window.draw(ball1Sprite);


	window.draw(charizardSprite);
	
	window.display();
}

int main()

{
	srand(time(NULL));							//this line will make the srand truly random, doesn't repeat itself
												//helps reset function

	sf::RenderWindow window(sf::VideoMode(1000, 800), "Cookie Game");
	window.setVerticalSyncEnabled(true);

	//event : all users input (a union), one input per line
	sf::Event event;		

	//Charizard 
	sf::Texture charizardTexture;
	charizardTexture.loadFromFile(resourcePath() + "assets/charizard.png");
	sf::Sprite charizardSprite(charizardTexture);
	charizardSprite.setPosition(LENGTHWINDOW, WIDTHWINDOW / 2.0);

	/* Cookie*/

	sf::Texture cookieTexture;
	cookieTexture.loadFromFile(resourcePath() + "assets/cookie.png");
	sf::Sprite cookieSprite(cookieTexture);
	cookieSprite.setScale(1, 1);

	/* Fire ball (100 x 100)*/
	sf::Texture fireTexture;
	fireTexture.loadFromFile(resourcePath() + "assets/Fireball.png");
	if (!fireTexture.loadFromFile((resourcePath() + "assets/Fireball.png")))
	{
		cout << "\nCan't load fireball.png into this program :(";
		return -1;				//stop program
		system("pause");
	}
	sf::Sprite fireSprite(fireTexture);
	fireSprite.setScale(2, 2);
	fireSprite.setOrigin(50, 50);
	vector<sf::Sprite> vectorFire;

	for (int count = 0; count < numFire; count++)
	{
		vectorFire.push_back(fireSprite);
		vectorFire[count].setPosition(rand() % (LENGTHWINDOW - 100), 100);
	}

	//check if two fireball overlap
	for (int count = 0; count < numFire; count++)
	{
		//sf::Vector2f position1 = vectorFire[count].getPosition();			//position of fireball[0]
		for (int counter = 1; counter < numFire - 1; counter++)
		{
			//sf::Vector2f position2 = vectorFire[count].getPosition();
			if (overlap(vectorFire[count], vectorFire[counter]))
			{
				vectorFire[counter].setPosition(rand() % (LENGTHWINDOW - 100) , 100);
			}
		}

	}


	/* pokeball */
	sf::Texture ballTexture;
	ballTexture.loadFromFile(resourcePath() + "assets/pokeball.jpg");

	sf::Sprite ball1Sprite(ballTexture);
	ball1Sprite.setScale(0.2, 0.2);
	ball1Sprite.setPosition(800 - 40, 40);
	ball1Sprite.setOrigin(100, 100);							//sfml ignore the fact that pokeball is scaled


	sf::Sprite ball2Sprite(ballTexture);
	ball2Sprite.setScale(0.2, 0.2);
	ball2Sprite.setPosition(800 - 40 - 50, 40);
	ball2Sprite.setOrigin(100, 100);


	sf::Sprite ball3Sprite(ballTexture);
	ball3Sprite.setScale(0.2, 0.2);
	ball3Sprite.setPosition(800 - 40 - 100, 40);
	ball3Sprite.setOrigin(100, 100);

	/* vector DG bullet*/
	sf::Texture dgTexture;
	dgTexture.loadFromFile(resourcePath() + "assets/dglogo.png");
	sf::Sprite dgSprite(dgTexture);
	dgSprite.setScale(0.05, 0.05);

	vector <sf::Sprite> vectorDg;
	vectorDg.push_back(dgSprite);
	int numOfDg = 0;

	/* vector cookie*/
	float x = 0;

	int score = 0;
	int LIVES = 0;

	vector <sf::Sprite> vectorCookie;				/** vector of cookies to print multiple cookies on window while playing **/


	for (int counter = 0; counter < numOfCookie; counter++)
	{
		vectorCookie.push_back(cookieSprite);
		vectorCookie[counter].setPosition(800, rand() % (600 - 64));
	}

	GAME_STATE state = OPENING_SCREEN;
	
	
	while (window.isOpen())
	{


		handleEvent(window);					//inside event.h
		switch (state)
		{
		case OPENING_SCREEN:
			openingScreen(window, LIVES, state);
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
				state = HOWTO_SCREEN;
			break;
		
		case HOWTO_SCREEN:
			HowToScreen(window, state, LIVES);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			{
				state = DURING_GAME;
				LIVES = 3;
			}
			break;

		case DURING_GAME:

			for (int count = 0; count < numOfCookie; count++)
			{
				if (!overlap(charizardSprite, vectorCookie[count]) && !overlap (charizardSprite, vectorFire[count]) && LIVES != 0)		//call this, before the first frame is drawn, it is false
				{
					update(charizardSprite, dgSprite, window, event, vectorDg, numOfDg, score, vectorCookie, numOfCookie, vectorFire, numFire, LIVES);
					updatePokeball(x, ball1Sprite, ball2Sprite, ball3Sprite);
					draw(window, charizardSprite, vectorDg, ball1Sprite, ball2Sprite, ball3Sprite, LIVES, vectorCookie, vectorFire, numFire);
				}

				else if (overlap(charizardSprite, vectorCookie[count]) || overlap(charizardSprite, vectorFire[count]) && LIVES != 0)
				{
					update(charizardSprite, dgSprite, window, event, vectorDg, numOfDg, score, vectorCookie, numOfCookie, vectorFire, numFire, LIVES);
					updatePokeball(x, ball1Sprite, ball2Sprite, ball3Sprite);
					draw(window, charizardSprite, vectorDg, ball1Sprite, ball2Sprite, ball3Sprite, LIVES, vectorCookie, vectorFire, numFire);
					LIVES -= 1;
					resetCookie(vectorCookie[count], numOfCookie);

				}	//end of overlap 

				else if (LIVES == 0)
					state = ENDING_GAME;
			}			//end of for (int count = 0; count < numOfCookie; count++)
			break;

		case ENDING_GAME:
			if (LIVES == 0)
				drawGameOverText(window, score);
			//end of for loop counting numOfCookie

			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
				LIVES = 3;
				state = DURING_GAME;
			break;

		}						//end of switch(state)		

	}					//end of while window is open
					
						
	int Quitdecision = 0;
	
	do
	{
		cout << "Final score" << score;
		cout << "\nTo close this window, press 'y' key" << endl;
		cin >> Quitdecision;
	} while (Quitdecision == 'y');

	return 0;
}

void resetCookie(sf::Sprite &cookieSprite, int numOfCookie)
{
	for (int count = 0; count < numOfCookie ; count++)
	{
		
		cookieSprite.setPosition(700, rand() % 500);

	}
}

/*
1) forgot ampersand in function declaration
2) Created a sprite (pitchfork) and update it then don't draw it, but thought something is wrong with the png
3) Remember draw() but forget to display      
4) problem with string at howTo screen, can't seem to setposition for instruction2 although I can setPosition for other string. Turns out, I mistook intruction2.setPosition
for instruction1.setPosition


*/
