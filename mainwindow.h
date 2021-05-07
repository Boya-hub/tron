#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow: public QMainWindow
{
public:
	MainWindow(unsigned int lenght, unsigned int width);
private:
	unsigned int m_lenght;
	unsigned int m_width;
	QWidget m_window;
};

#endif // MAINWINDOW_H
