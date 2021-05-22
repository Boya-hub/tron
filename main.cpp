#include <QApplication>
#include <QWidget>
#include <SFML/Graphics.hpp>
#include <QResource>
#include <iostream>
#include "main.h"
#include "mainwindow.h"
#include "gamewindow.h"

using namespace sf;
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	unsigned long long  lli = 0;
	unsigned long long frameNumber = 0;
	unsigned int winner = 0;

	MainWindow window(FENETRE_LENGHT, FENETRE_WIDTH, 64, "Tron", ":/resources/sprite/background.jpg", \
					  ":/resources/fonts/Sunday Best.ttf", ":/resources/musics/Son-of-Flynn.wav");
	window.setFramerateLimit(100);
	window.setVerticalSyncEnabled(true);

	Event event;
	while(window.isOpen()){
		while (window.pollEvent(event))
		{
			if(event.type == Event::Closed){
				window.close();
				return EXIT_SUCCESS;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				window.close();
		}
		//Display
		window.clear();
		window.draw(window.getBackground());
		for(lli = 0; lli < frameNumber; lli++){
			if(lli < window.getLetterT().size())
				window.draw(window.getLetterT()[lli]);
		}
		for(lli = 0; lli < frameNumber; lli++){
			if(lli < window.getLetterR().size())
				window.draw(window.getLetterR()[lli]);
		}
		for(lli = 0; lli < frameNumber; lli++){
			if(lli < window.getLetterO().size())
				window.draw(window.getLetterO()[lli]);
		}
		for(lli = 0; lli < frameNumber; lli++){
			if(lli < window.getLetterN().size())
				window.draw(window.getLetterN()[lli]);
		}
		window.blinkText();
		window.draw(window.getText());
		window.display();
		if(frameNumber < MAX_FRAME_MAINWINDOW)
			frameNumber++;
	}


	//Game
	GameWindow game(FENETRE_LENGHT, FENETRE_WIDTH, 64, "Tron2", ":/resources/sprite/background.jpg", \
					":/resources/fonts/Sunday Best.ttf");
	game.setFramerateLimit(60);
	while(game.isOpen()){
		while (game.pollEvent(event))
		{
			if(event.type == Event::Closed){
				game.close();
				return EXIT_SUCCESS;
			}
			//Ctrl player 1
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
				game.setDirection(1, DIRECTION_UP);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				game.setDirection(1, DIRECTION_DOWN);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				game.setDirection(1, DIRECTION_LEFT);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				game.setDirection(1, DIRECTION_RIGHT);
			//Ctrl player 2
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				game.setDirection(2, DIRECTION_UP);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				game.setDirection(2, DIRECTION_DOWN);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				game.setDirection(2, DIRECTION_LEFT);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				game.setDirection(2, DIRECTION_RIGHT);

		}
		//Display
		game.clear();
		game.draw(window.getBackground());
		game.movePlayer(1);
		game.drawPlayer(1);
		game.movePlayer(2);
		game.drawPlayer(2);
		winner = game.collisionManagement();
		if(winner){
			game.drawWinner(winner);
		}
		game.display();
	}
	return app.exec();
}
