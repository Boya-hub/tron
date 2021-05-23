#include "player.h"

Player::Player(unsigned int posX, unsigned int posY, Color color):m_startPosX(posX), m_startPosY(posY),\
  m_color(color)
{
	addCircle(posX, posY);
}


void Player::addCircle(unsigned int posX, unsigned posY)
{
	CircleShape circle(LETTER_WIDTH);
	circle.setOutlineColor(Color::Black);
	circle.setFillColor(m_color);
	circle.setOutlineThickness(1.2);	//TODO : Trouver une bonne epaisseur
	circle.setPosition(posX, posY);
	shapes.push_back(circle);
}

void Player::move()
{
	CircleShape circle(shapes.back());
	Vector2f pos;

	switch(m_direction){
	case DIRECTION_DOWN:
		circle.move(0, VITESSE_PLAYER);
		break;
	case DIRECTION_LEFT:
		circle.move(-VITESSE_PLAYER, 0);
		break;
	case DIRECTION_UP:
		circle.move(0, -VITESSE_PLAYER);
		break;
	case DIRECTION_RIGHT:
		circle.move(VITESSE_PLAYER, 0);
		break;
	}
	pos = circle.getPosition();
	if(pos.x <= -10)
		circle.setPosition(FENETRE_LENGHT, pos.y);
	if(pos.x >= FENETRE_LENGHT)
		circle.setPosition(0, pos.y);
	if(pos.y <= -10)
		circle.setPosition(pos.x, FENETRE_WIDTH);
	if(pos.y >= FENETRE_WIDTH)
		circle.setPosition(pos.x, 0);
	shapes.push_back(circle);

}

void Player::setDirection(Direction direction, bool const force){
	switch(direction){
	case DIRECTION_DOWN:
		if(m_direction != DIRECTION_UP || force)
			m_direction = direction;
		break;
	case DIRECTION_LEFT:
		if(m_direction != DIRECTION_RIGHT || force)
			m_direction = direction;
		break;
	case DIRECTION_UP:
		if(m_direction != DIRECTION_DOWN || force)
			m_direction = direction;
		break;
	case DIRECTION_RIGHT:
		if(m_direction != DIRECTION_LEFT || force)
			m_direction = direction;
		break;
	}
}

void Player::resetPlayer()
{
	std::vector<CircleShape>().swap(shapes);
	//shapes.clear();
	CircleShape circle(LETTER_WIDTH);
	circle.setOutlineColor(Color::Black);
	circle.setFillColor(m_color);
	circle.setOutlineThickness(1.2);	//TODO : Trouver une bonne epaisseur
	circle.setPosition(m_startPosX, m_startPosY);
	shapes.push_back(circle);
}

Player::~Player()
{
	//Destructor
}
