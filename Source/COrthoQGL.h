#ifndef CORTHOQGL_H
#define CORTHOQGL_H
#include "CBaseQGL.h"
#include "CDebug.h"
class COrthoQGL : public CBaseQGL {
	public:
		COrthoQGL(int timeInterval=0, QWidget* parent=0) :CBaseQGL (timeInterval, parent) {
		}
	protected:
		virtual void initializeGL() {
			glClearColor (0,0,0,0);
			glShadeModel(GL_FLAT);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		virtual void resizeGL (int width, int height) {
			glViewport(0, 0, width, height);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho (0, width, 0, height, -1, 1);
			glMatrixMode(GL_MODELVIEW);
		}
};

#endif
