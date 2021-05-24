#include "smileyface.h"

SmileyFace::SmileyFace()
{
	QResource texture_file(":/resources/sprite/smileys-emotion-00.png");
	m_texture.loadFromMemory(texture_file.data(), texture_file.size());
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(588, 12, 49, 49));
	m_sprite.setScale(0.4, 0.4);
}

void SmileyFace::setPosition(unsigned int posX, unsigned int posY)
{
	m_sprite.setPosition(posX, posY);
}

void SmileyFace::chooseSprite(Faces face)
{
	switch(face){
	case NORMAL:
		m_sprite.setTextureRect(sf::IntRect(588, 12, 49, 49));
		break;
	case SAD:
		m_sprite.setTextureRect(sf::IntRect(227, 300, 49, 49));
		break;
	case HAPPY:
		m_sprite.setTextureRect(sf::IntRect(155, 11, 49, 49));
		break;
	}
}

SmileyFace::~SmileyFace()
{

}

