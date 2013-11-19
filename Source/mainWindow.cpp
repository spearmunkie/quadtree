#include "mainWindow.h"
mainWindow::mainWindow(QMainWindow *parent):QMainWindow(parent) {
	
	setupUi(this);
	wid = new quadtreeTest;
	glContainer->addWidget( wid );

	connect(moreBalls, SIGNAL(clicked()), wid, SLOT(addMoreBalls()));

	connect(useQuad, SIGNAL(stateChanged(int)), this, SLOT(toggleUseQuad(int)));

	connect(drawQuad, SIGNAL(stateChanged(int)), this, SLOT(toggleDrawQuad(int)));
	
	connect(drawOppQuad, SIGNAL(stateChanged(int)), this, SLOT(toggleDrawOppQuad(int)));

	connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));

	connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
}

void mainWindow::toggleUseQuad(int state) {
	wid->toggleUseQuad();

	if (state == 0) {
		drawQuad->setCheckState(Qt::Unchecked);
		drawQuad->setEnabled(false);

		drawOppQuad->setCheckState(Qt::Unchecked);
		drawOppQuad->setEnabled(false);


	} else {
		drawQuad->setEnabled(true);
		drawOppQuad->setEnabled(true);
	}

}

void mainWindow::toggleDrawQuad(int state) {
	wid->toggleDrawQuad(state != Qt::Unchecked );

	if (useQuad->checkState() != Qt::Unchecked) {
		if(state == 2) {
			drawOppQuad->setCheckState(Qt::Unchecked);
		}
	} 
}

void mainWindow::toggleDrawOppQuad(int state) {
	wid->toggleDrawOppQuad(state != Qt::Unchecked );

	if (useQuad->checkState() != Qt::Unchecked) {
		if(state == 2) {
			drawQuad->setCheckState(Qt::Unchecked);
		}
	} 
}

void mainWindow::about() {
		QMessageBox::about(this, tr("About Quadtree"),
								 tr("<h2>Quatree Test</h2>"
								    "<p>This is my Quadtree implementation. I used a quadtree to detect potential ball-ball collisions</p>"));
}


