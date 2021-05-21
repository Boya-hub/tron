#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <QResource>
#include "main.h"
#include <vector>

#define LETTER_T 1
#define LETTER_R 2
#define LETTER_O 3
#define LETTER_N 4

using namespace sf;

class MainWindow: public RenderWindow
{
public:
	MainWindow(unsigned int lenght, unsigned int width, unsigned int fps, std::string name, QString file, QString font, QString music);
	virtual ~MainWindow();

	Sprite getBackground() const {return m_sprite;};
	std::vector<CircleShape> &getLetterT() {return m_letterT;};
	std::vector<CircleShape> &getLetterR() {return m_letterR;};
	std::vector<CircleShape> &getLetterO() {return m_letterO;};
	std::vector<CircleShape> &getLetterN() {return m_letterN;};
	void addLetter(std::vector<CircleShape>& vect, const double x, const double y);
	Text &getText() {return m_text;};
	void blinkText();
private:
	unsigned int m_lenght;
	unsigned int m_width;
	Texture m_texture;
	Sprite m_sprite;
	std::vector<CircleShape> m_letterT;
	std::vector<CircleShape> m_letterR;
	std::vector<CircleShape> m_letterO;
	std::vector<CircleShape> m_letterN;
	Text m_text;
	Font m_font;
	Music m_music;
};

#endif // MAINWINDOW_H
