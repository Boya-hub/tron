#include "mainwindow.h"

MainWindow::MainWindow(unsigned int lenght, unsigned int width, unsigned int fps,\
			std:: string name):RenderWindow(VideoMode(lenght, width, fps), name),\
			m_lenght(lenght), m_width(width)
{
	int i = 0;
	CircleShape circle(LETTER_WIDTH);
	circle.setOutlineColor(Color::Black);
	circle.setOutlineThickness(1.2);
	//-----Lettre T-----
	m_letterT.push_back(circle);
	m_letterT[0].setFillColor(Color::Blue);
	m_letterT[0].setPosition(FENETRE_LENGHT/4+60, FENETRE_WIDTH/3);
	//Up
	for(i = 1; i < 25; i++)
		addLetter(m_letterT, 0, -4);
	//left
	for(i = 1; i < 12; i++)
		addLetter(m_letterT, -4.16, 0);
	//right
	for(i = 1; i < 25; i++)
		addLetter(m_letterT, 4, 0);
	//-----Lettre R-----
	m_letterR.push_back(circle);
	m_letterR[0].setFillColor(Color::Green);
	m_letterR[0].setPosition(5*FENETRE_LENGHT/12, FENETRE_WIDTH/3);
	for(i = 1; i < 25; i++)
		addLetter(m_letterR, 0, -4);
	for(i = 1; i < 8; i++)
		addLetter(m_letterR, 3.66, 0);
	for(i = 1; i < 4; i++)
		addLetter(m_letterR, 3.66, 3.66);
	for(i = 1; i < 8; i++)
		addLetter(m_letterR, 0, 3.66);
	for(i = 1; i < 4; i++)
		addLetter(m_letterR, -3.66, 3.66);
	for(i = 1; i < 4; i++)
		addLetter(m_letterR, -3.66, 0);
	for(i = 1; i < 13; i++)
		addLetter(m_letterR, 3, 4);
	//-----Lettre O-----
	circle.setFillColor(Color::Red);
	m_letterO.push_back(circle);
	m_letterO[0].setPosition(7*FENETRE_LENGHT/12-40, FENETRE_WIDTH/3);
	for(i = 1; i < 9; i++)
		addLetter(m_letterO, -3.66, -3.66);
	for(i = 1; i < 9; i++)
		addLetter(m_letterO, 0, -3.66);
	for(i = 1; i < 9; i++)
		addLetter(m_letterO, 3.66, -3.66);
	for(i = 1; i < 9; i++)
		addLetter(m_letterO, 3.66, 0);
	for(i = 1; i < 9; i++)
		addLetter(m_letterO, 3.66, 3.66);
	for(i = 1; i < 9; i++)
		addLetter(m_letterO, 0, 3.66);
	for(i = 1; i < 9; i++)
		addLetter(m_letterO, -3.66, 3.66);
	for(i = 1; i < 9; i++)
		addLetter(m_letterO, -3.66, 0);
	//-----Lettre N-----
	m_letterN.push_back(circle);
	m_letterN[0].setFillColor(Color::Cyan);
	m_letterN[0].setPosition(3*FENETRE_LENGHT/4-100, FENETRE_WIDTH/3);
	for(i = 1; i < 25; i++)
		addLetter(m_letterN, 0, -4);
	for(i = 1; i < 17; i++)
		addLetter(m_letterN, 4, 5.88);
	for(i = 1; i < 25; i++)
		addLetter(m_letterN, 0, -4);

	//Backgroung
	QResource bakcground_file(":/resources/sprite/background.jpg");
	m_texture.loadFromMemory(bakcground_file.data(), bakcground_file.size());
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.scale(1.5, 1.5);

	//Font
	QResource font_file(":/resources/fonts/Sunday Best.ttf");
	m_font.loadFromMemory(font_file.data(), font_file.size());
	m_text.setFont(m_font);
	m_text.setString("Press SPACE to play");
	m_text.setCharacterSize(23);
	m_text.setFillColor(Color::White);
	m_text.setOutlineColor(Color::Magenta);
	m_text.setOutlineThickness(4);
	m_text.setPosition(FENETRE_LENGHT/2-145, FENETRE_WIDTH/2+175);

	//Musique
	QResource music_file(":/resources/musics/Son-of-Flynn.wav");
	m_music.openFromMemory(music_file.data(), music_file.size());
	m_music.setLoop(true);
	m_music.setVolume(5);
	m_music.play();
}

MainWindow::~MainWindow()
{
	// destructor
}

void MainWindow::addLetter(std::vector<CircleShape>& vect, const double x, const double y)
{
	CircleShape circle(vect.back());
	circle.move(x, y);
	vect.push_back(circle);
}

void MainWindow::blinkText()
{
	static bool direction = false;
	float thickness = m_text.getOutlineThickness();
	if(thickness <= 0 )
		direction = true;
	else if(thickness >= 5)
		direction = false;
	if(direction == false)
		m_text.setOutlineThickness(thickness-0.1);
	else
		m_text.setOutlineThickness(thickness+0.1);
}
