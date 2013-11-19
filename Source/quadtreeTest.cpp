#include "quadtreeTest.h"

quadtreeTest::quadtreeTest(QWidget *parent) : COrthoQGL(1, parent) {
}

void quadtreeTest::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ballMngr.draw();
}

void quadtreeTest::timeOut() {
	ballMngr.update(0.016);
	updateGL();
}

void quadtreeTest::resizeGL(int width, int height) {
	COrthoQGL::resizeGL(width, height);
	ballMngr.resize(width, height);
}

void quadtreeTest::addMoreBalls() {
	ballMngr.addMoreBalls();
}

void quadtreeTest::toggleUseQuad () {
	ballMngr.toggleUseQuad();
}

void quadtreeTest::toggleDrawOppQuad (bool state) {
	ballMngr.toggleDrawOppQuad(state);
}

void quadtreeTest::toggleDrawQuad(bool state) {
	ballMngr.toggleDrawQuad(state);
}
