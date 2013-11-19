#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
//#include <qmessagebox.h>
#include "../.tmp/UISrc/ui_quadtree.h"
#include "quadtreeTest.h"

class mainWindow : public QMainWindow, public Ui::MainWindow {
	Q_OBJECT
	
	public:
		mainWindow(QMainWindow *parent = 0);

	public slots:
		void toggleUseQuad(int state);
		void toggleDrawQuad(int state);
		void toggleDrawOppQuad(int state);
	private slots:
		void about();
	private:
		quadtreeTest* wid;
};

#endif
