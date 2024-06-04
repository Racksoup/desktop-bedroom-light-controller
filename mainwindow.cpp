#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow()
{
	set_child(m_ui.m_box);
	std::cout << "Hello World!" << std::endl;
}

MainWindow::~MainWindow()
{
}
