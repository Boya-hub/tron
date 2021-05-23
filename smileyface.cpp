#include "smileyface.h"

SmileyFace::SmileyFace()
{
	QResource texture_file(":/resources/sprite/smileys-emotion-00.png");
	m_texture.loadFromMemory(texture_file.data(), texture_file.size());
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(150, 10, 60, 60));
}

void SmileyFace::setPosition(unsigned int posX, unsigned int posY)
{
	m_sprite.setPosition(posX, posY);
}

SmileyFace::~SmileyFace()
{

}

