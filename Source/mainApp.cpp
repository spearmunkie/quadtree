#include <QApplication>
#include <iostream>
//#include <time.h>

#include "mainWindow.h"
#include "CDebug.h"
#include <IL/il.h>

std::ofstream CDebug("debug.txt");
int main(int argc, char *argv[])
{
	ilInit();
	srand ( time(NULL) );

	QApplication app(argc, argv);
	if (!QGLFormat::hasOpenGL()) {
		std::cout<< "This system has no OpenGL support" << std::endl;
		return 1;
	}
	mainWindow win;
	win.show();
	return app.exec();
}

