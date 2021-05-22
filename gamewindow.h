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
	GameWindow(unsigned int lenght, unsigned int width, unsigned int fps, std::string name, QString file,\
			   QString font);
	virtual ~GameWindow();
	Sprite getBackground() const {return m_sprite;};
	void drawPlayer(unsigned int const player);
	void movePlayer(unsigned int const player);
	void setDirection(unsigned int const player, Direction direction);
	unsigned int collisionManagement();
	void drawWinner(unsigned int const player);

private:
	unsigned int m_lenght;
	unsigned int m_width;
	Texture m_texture;
	Sprite m_sprite;
	Player m_player1;
	Player m_player2;
	Font m_font;
	Text m_text;

	bool collide(Vector2f pos1, Vector2f pos2);
};

#endif // GAMEWINDOW_H
