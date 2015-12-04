#include "Event.h"


void handleEvent(sf::RenderWindow& window)			//to close window
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

}
