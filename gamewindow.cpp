#include "gamewindow.h"

GameWindow::GameWindow(unsigned int lenght, unsigned int width, unsigned int fps, std::string name, QString file)\
	:RenderWindow(VideoMode(lenght, width, fps), name), m_lenght(lenght), m_width(width),\
	  m_player1(FENETRE_LENGHT/3, FENETRE_WIDTH/2, Color::Red),\
	  m_player2((2*FENETRE_LENGHT)/3, FENETRE_WIDTH/2, Color::Blue)
{
	//Backgroung
	QResource bakcground_file(file);
	m_texture.loadFromMemory(bakcground_file.data(), bakcground_file.size());
	m_sprite.setTexture(m_texture);
	m_sprite.scale(1.5, 1.5);
	draw(m_sprite);
	//Gestion joueurs
	m_player1.setDirection(DIRECTION_RIGHT);
	m_player2.setDirection(DIRECTION_LEFT);
	drawPlayer(1);
	drawPlayer(2);
	display();

}

void GameWindow::drawPlayer(unsigned int player)
{
	unsigned long long lli = 0;
	if(player == 1){
		for(lli = 0; lli < m_player1.getShapes().size(); lli++){
			draw(m_player1.getShapes()[lli]);
		}
	}
	else{
		for(lli = 0; lli < m_player2.getShapes().size(); lli++){
			draw(m_player2.getShapes()[lli]);
		}
	}
}

void GameWindow::movePlayer(unsigned player)
{
	if(player == 1)
		m_player1.move();
	else
		m_player2.move();
}

void GameWindow::setDirection(unsigned player, Direction direction)
{
	if(player == 1)
		m_player1.setDirection(direction);
	else
		m_player2.setDirection(direction);
}

GameWindow::~GameWindow()
{
	// destructor
}
