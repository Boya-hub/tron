#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "main.h"
#include <SFML/Graphics.hpp>
#include <QResource>

using namespace sf;

class GameWindow: public RenderWindow
{
public:
	GameWindow(unsigned int lenght, unsigned int width, unsigned int fps, std::string name, QString file);
	virtual ~GameWindow();
	Sprite getBackground() const {return m_sprite;};

private:
	unsigned int m_lenght;
	unsigned int m_width;
	Texture m_texture;
	Sprite m_sprite;
};

#endif // GAMEWINDOW_H
