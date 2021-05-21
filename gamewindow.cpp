#include "gamewindow.h"

GameWindow::GameWindow(unsigned int lenght, unsigned int width, unsigned int fps, std::string name, QString file)\
	:RenderWindow(VideoMode(lenght, width, fps), name), m_lenght(lenght), m_width(width)
{
	//Backgroung
	QResource bakcground_file(file);
	m_texture.loadFromMemory(bakcground_file.data(), bakcground_file.size());
	m_sprite.setTexture(m_texture);
	m_sprite.scale(1.5, 1.5);
	draw(m_sprite);
	display();

}

GameWindow::~GameWindow()
{
	// destructor
}
