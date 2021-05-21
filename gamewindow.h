#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "main.h"
#include <SFML/Graphics.hpp>
#include <QResource>
#include "player.h"

using namespace sf;

class GameWindow: public RenderWindow
{
public:
	GameWindow(unsigned int lenght, unsigned int width, unsigned int fps, std::string name, QString file);
	virtual ~GameWindow();
	Sprite getBackground() const {return m_sprite;};
	void drawPlayer(unsigned int player);
	void movePlayer(unsigned player);
	void setDirection(unsigned player, Direction direction);

private:
	unsigned int m_lenght;
	unsigned int m_width;
	Texture m_texture;
	Sprite m_sprite;
	Player m_player1;
	Player m_player2;
};

#endif // GAMEWINDOW_H
