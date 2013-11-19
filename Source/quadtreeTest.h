#ifndef QUADTREETEST_H
#define QUADTREETEST_H
#include "COrthoQGL.h"
#include "CBalls.h"

class quadtreeTest :public COrthoQGL  {
	Q_OBJECT
	public:
		quadtreeTest(QWidget *parent=0);
		
		void toggleUseQuad ();
		void toggleDrawOppQuad (bool state);
		void toggleDrawQuad (bool state);
	protected:
		void paintGL();
		void timeOut();
		void resizeGL (int width, int height);
		
	public slots:
		void addMoreBalls();
	private:
		ballManager ballMngr;
};
#endif
	
