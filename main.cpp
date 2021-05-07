#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <SFML/Graphics.hpp>

#include "main.h"

using namespace sf;
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QPushButton bouton("Salut les Zéros, la forme ?");
	bouton.show();
	RenderWindow window(VideoMode(2000, 600), "tron");
	Event event;
	while(window.isOpen()){
		while (window.pollEvent(event))
		{
			if(event.type == Event::Closed){
				window.close();
				return EXIT_SUCCESS;
			}
		}
	}
	return app.exec();
}
