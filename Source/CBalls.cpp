#include "CImage.h"
#include "CBalls.h"
#include "CDebug.h"
#define DEBUG CDebug<<"CBalls: "
GLuint circle;
GLuint cirTex;
int initiated = 0;

void genDisplayList() {
   initiated = 1;
	circle=glGenLists(1);
	glNewList(circle, GL_COMPILE);

	glBegin(GL_QUADS);
		   glTexCoord2f(0,0);glVertex2i(0,0); 
        	glTexCoord2f(1,0);glVertex2i(1,0);
        	glTexCoord2f(1,1);glVertex2i(1,1);
        	glTexCoord2f(0,1);glVertex2d(0,1);
	glEnd();
	glEndList();
	CImage tmp;
	cirTex = tmp.load("Images/circle.png");
}

void ball::draw() {
   	if(initiated == 0) genDisplayList();
	glBindTexture(GL_TEXTURE_2D,cirTex);
	//glTranslated(pos[0], pos[1],0);
	//glScalef(-r,r,1);
	glPushMatrix();
	glLoadIdentity();
	glTranslated(pos[0] + r/2, pos[1] -r/2,0);
	glScalef(-r,r,1);
	glColor3f(col[0],col[1],col[2]);
	glCallList(circle);
	glPopMatrix();
	
}

ballManager::ballManager() {

	width = 150;
	height = 150;
	balls.resize(5);
	for(int i=0; i<5; i++) {
		balls[i].pos = CMath::vec4f( CMath::randFloat(0, width),
							CMath::randFloat(0, height) );

		balls[i].vel = CMath::vec4f( CMath::randFloat(-25,25),
							CMath::randFloat(-25,25) );

		balls[i].col = CMath::vec4f( CMath::randFloat(0,1),
							CMath::randFloat(0,1), 
							CMath::randFloat(0,1) );

		balls[i].r = CMath::randFloat(15, 35);
	}
	
	useQuad = false;
	drawQuad = false;
	drawOppQuad = false;
	gravity = -0.1;
}

void ballManager::toggleUseQuad() {
	useQuad = !useQuad;
	if(!useQuad) {
		drawQuad = false;
		drawOppQuad = false;
	}
}

void ballManager::toggleDrawQuad(bool state) {
	drawQuad = state;
	
	if(drawQuad) {
		drawOppQuad = false;
	}

	if(!useQuad) {
		drawQuad = false;
		drawOppQuad = false;
	}
}

void ballManager::toggleDrawOppQuad(bool state) {
	drawOppQuad = state;
	
	if(drawOppQuad) {
		drawQuad = false;
	}

	if(!useQuad) {
		drawQuad = false;
		drawOppQuad = false;
	}
}

void ballManager::resize (int w, int h) {
	width = w;
	height = h;

	tree.buildTree(CMath::vec4f(0,0),
				   CMath::vec4f(w,h), 0);
}

bool areColliding(ball b1, ball b2,float  msec) {
	return ((b1.r/2 + b2.r/2) >= CMath::distance(b1.pos + b1.vel*msec, b2.pos + b2.vel*msec));
}

void ballManager::handleCollisions(float msec) {
	
	if (useQuad) {
		CDebug<<"QuadTree in use\n";
		tree.destroyTree();
		for(int i = 0; i < balls.size(); i++) {
			tree.insertNode(i, balls[i].pos, balls[i].r/2);
		}
		std::vector<items> tmp =tree.getNodeData();
		for(int x =0; x< tmp.size(); x+=1) {
			for(int i=0; i<tmp[x].numItems; i+=1) {
				for(int j = i + 1; j<tmp[x].numItems; j += 1) {

					int I = tmp[x].items[i], J = tmp[x].items[j];

					if(areColliding(balls[I], balls[J], msec)) {
						CMath::vec4f u1=balls[I].vel, u2=balls[J].vel;
						float m1 =balls[I].r/10, m2=balls[J].r/10;
						balls[I].vel = (u1*(m1 -m2) + u2*2*m2)/(m1+m2);
						balls[J].vel = (u2*(m2 -m1) + u1*2*m1)/(m1+m2);
					}
				}
			}
		}
	}
	else {
		for(int i = 0; i < balls.size(); i++) {
			for(int j = i + 1; j < balls.size(); j++) {
				if(areColliding(balls[i], balls[j], msec)) {
					CMath::vec4f u1=balls[i].vel, u2=balls[j].vel;
					float m1 =balls[i].r/10, m2=balls[j].r/10;
					balls[i].vel = (u1*(m1 -m2) + u2*2*m2)/(m1+m2);
					balls[j].vel = (u2*(m2 -m1) + u1*2*m1)/(m1+m2);
				}
			}
		}
	}
}

void ballManager::update (float msec) {
	
	for (int i=0; i<balls.size(); i++) {
		balls[i].vel[1] += gravity*balls[i].r/10;
	}
	
	for (int i=0; i<balls.size(); i++) {
		if (balls[i].pos[0] -balls[i].r/2 + balls[i].vel[0]*msec <= 0 || balls[i].pos[0] +balls[i].r/2+ balls[i].vel[0]*msec >= width)
			balls[i].vel[0] *= -1;
		
		if (balls[i].pos[1] -balls[i].r/2+ balls[i].vel[1]*msec <= 0 || balls[i].pos[1] +balls[i].r/2+ balls[i].vel[1]*msec >= height)
			balls[i].vel[1] *= -1;
	}
	
	handleCollisions(msec);

	for (int i=0; i<balls.size(); i+=1) {
		balls[i].pos += balls[i].vel*msec;
	}
}

void ballManager::addMoreBalls() {
	for(int i=0; i<5; i+=1) {
		ball tmp;
		tmp.pos = CMath::vec4f( CMath::randFloat(0, width),
							CMath::randFloat(0, height) );

		tmp.vel = CMath::vec4f( CMath::randFloat(-25,25),
							CMath::randFloat(-25,25) );

		tmp.col = CMath::vec4f( CMath::randFloat(0,1),
							CMath::randFloat(0,1), 
							CMath::randFloat(0,1) );

		tmp.r = CMath::randFloat(15, 35);

		balls.push_back(tmp);
	}
}



void ballManager::draw() {
	for(int i=0; i<balls.size(); i++) {
		balls[i].draw();
	}
	
	if (drawOppQuad)
		tree.drawOptimizedNode();
	if(drawQuad)
		tree.drawNode();
}
