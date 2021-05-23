#ifndef PLAYER_H
#define PLAYER_H

#include <QResource>
#include <SFML/Graphics.hpp>
#include "main.h"
#include <vector>
#include "smileyface.h"

#define VITESSE_PLAYER 4
using namespace sf;

enum Direction{DIRECTION_UP = 0, DIRECTION_DOWN, DIRECTION_LEFT, DIRECTION_RIGHT};

class Player
{
public:
	Player(unsigned int posX, unsigned int posY, Color color);
	virtual ~Player();

	std::vector<CircleShape> &getShapes() {return shapes;};
	void move();
	void setDirection(Direction direction, bool const force = false);
	void resetPlayer();
	Sprite getSmiley () const {return m_smileyFace.getSprite();};

private:
	unsigned int m_startPosX;
	unsigned int m_startPosY;
	Color m_color;
	std::vector<CircleShape> shapes;
	Direction m_direction;
	SmileyFace m_smileyFace;
};

#endif // PLAYER_H
