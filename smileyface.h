#ifndef SMILEYFACE_H
#define SMILEYFACE_H

#include <SFML/Graphics.hpp>
#include <QResource>

enum Faces{NORMAL = 0, SAD, HAPPY};

using namespace sf;

class SmileyFace
{
public:
	SmileyFace();
	virtual ~SmileyFace();
	void setPosition(unsigned int posW, unsigned int posY);
	Sprite getSprite () const {return m_sprite;};
	void chooseSprite(Faces face);

private:
	Texture m_texture;
	Sprite m_sprite;
};

#endif // SMILEYFACE_H
