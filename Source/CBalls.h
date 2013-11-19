#ifndef CBALLS_H
#define CBALLS_H

#include "CMath.h"
#include "CQuadtree.h"
#include <vector>

struct ball {
	public:
		CMath::vec4f pos,vel,col;
		float r;
		void draw();
};

class ballManager {
	public:
		ballManager();
		void addMoreBalls();
		void resize(int w, int h);
		void update(float msec);
		void draw();

		void toggleUseQuad ();
		void toggleDrawOppQuad (bool state);
		void toggleDrawQuad (bool state);
	private:
		std::vector<ball> balls;
		float gravity;
		int height, width;
		CQuadtree tree;
		bool useQuad,drawQuad,drawOppQuad;
		void handleCollisions(float msec);
};

#endif
