#include "stdafx.h"
#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

int main()
{
	sf::RenderWindow mainWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TicTacToe");
	
	while (mainWindow.isOpen()) 
	{
		sf::Event mainEvent;

		while (mainWindow.pollEvent(mainEvent))
		{
			switch (mainEvent.type) 
			{
				case sf::Event::Closed:
				{
					mainWindow.close();
					break;
				}
			}
		}

		mainWindow.clear();
		mainWindow.display();
	}
    
}

