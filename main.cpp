#include <QApplication>
#include <QWidget>
#include <SFML/Graphics.hpp>
#include <QResource>
#include <iostream>
#include "main.h"
#include "mainwindow.h"

using namespace sf;
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	unsigned long long  lli = 0;
	MainWindow window(FENETRE_LENGHT, FENETRE_WIDTH, 64, "Tron", ":/resources/sprite/background.jpg", ":/resources/fonts/Sunday Best.ttf", ":/resources/musics/Son-of-Flynn.wav");
	window.setFramerateLimit(100);
	window.setVerticalSyncEnabled(true);
	unsigned long long frameNumber = 0;
	Event event;
	while(window.isOpen()){
		while (window.pollEvent(event))
		{
			if(event.type == Event::Closed){
				window.close();
				return EXIT_SUCCESS;
			}
			/*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				window.addLetter(LETTER_T, (FENETRE_LENGHT/4)-10, FENETRE_WIDTH/3);*/
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
	return app.exec();
}
