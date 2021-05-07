#include "mainwindow.h"


MainWindow::MainWindow(unsigned int lenght, unsigned int width):m_lenght(lenght), m_width(width)
{
	m_window.setFixedSize(1000, 500);
	m_window.show();
}
