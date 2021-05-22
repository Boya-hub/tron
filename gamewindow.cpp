#include "gamewindow.h"

GameWindow::GameWindow(unsigned int lenght, unsigned int width, unsigned int fps, std::string name,\
					   QString file, QString font)\
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
	//Font
	QResource font_file(font);
	m_font.loadFromMemory(font_file.data(), font_file.size());
	m_text.setFont(m_font);
	m_text.setString("WIN");
	m_text.setCharacterSize(50);
	m_text.setPosition(FENETRE_LENGHT/2-145, FENETRE_WIDTH/2+175);
	//Gestion joueurs
	m_player1.setDirection(DIRECTION_RIGHT, true);
	m_player2.setDirection(DIRECTION_LEFT, true);
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

void GameWindow::movePlayer(unsigned int const player)
{
	if(player == 1)
		m_player1.move();
	else
		m_player2.move();
}

void GameWindow::setDirection(unsigned int const player, Direction direction)
{
	if(player == 1)
		m_player1.setDirection(direction);
	else
		m_player2.setDirection(direction);
}

unsigned int GameWindow::collisionManagement()
{
	unsigned int lli = 0;
	Vector2f posPlayer1, posPlayer2;
	//Does last circle of player 1 collide player 2
	posPlayer1 = m_player1.getShapes().back().getPosition();
	for(lli = 0; lli < m_player2.getShapes().size(); lli++){
		posPlayer2 = m_player2.getShapes()[lli].getPosition();
		if(collide(posPlayer1, posPlayer2))
			return 1;
	}

	//Does last circle of player 2 collide player 1
	posPlayer2 = m_player2.getShapes().back().getPosition();
	for(lli = 0; lli < m_player1.getShapes().size(); lli++){
		posPlayer1 = m_player1.getShapes()[lli].getPosition();
		if(collide(posPlayer1, posPlayer2))
			return 2;
	}
	return 0;
}

void GameWindow::drawWinner(unsigned int const player)
{
	if(player == 1)
		m_text.setFillColor(Color::Blue);
	if(player == 2)
		m_text.setFillColor(Color::Red);
	draw(m_text);
}

bool GameWindow::collide(Vector2f pos1, Vector2f pos2)
{
	if(pos1.x < pos2.x + LETTER_WIDTH && pos1.x > pos2.x - LETTER_WIDTH && \
	   pos1.y < pos2.y + LETTER_WIDTH && pos1.y > pos2.y - LETTER_WIDTH)
		return true;
	return false;
}

GameWindow::~GameWindow()
{
	// destructor
}
