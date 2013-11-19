#include "CQuadtree.h"
#include "CDebug.h"

#define DEPTH 5
#define MAX_IN_NODE 10

CQuadtree::CQuadtree() {
	inNode.numItems = 50;
	inNode.items = new int [50];
	currentNumItems = 0;
	nodes = NULL;
	hasChildren = false;
}

void CQuadtree::buildTree(CMath::vec4f m, CMath::vec4f mx, int d) {
	min = m;
	max = mx;
	depth =d;
	if (d>DEPTH) {
		hasChildren=false;
		return;
	}
	
	hasChildren = true;
	CMath::vec4f c = (min + max)/2;
	nodes = new CQuadtree[4];
	nodes[0].buildTree(CMath::vec4f(min[0], c[1]),
					   CMath::vec4f(c[0], max[1]), d + 1 );

	nodes[1].buildTree(CMath::vec4f(c[0], c[1]),
					   CMath::vec4f(max[0], max[1]), d + 1  );

	nodes[2].buildTree(CMath::vec4f(min[0], min[1]),
					   CMath::vec4f(c[0], c[1]), d + 1  );

	nodes[3].buildTree(CMath::vec4f(c[0], min[1]),
					   CMath::vec4f(max[0], c[1]), d + 1  );
}

void CQuadtree::drawNode() {
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glColor3f(1,1,1);
	glBegin(GL_LINES);

		glVertex2f(min[0], min[1]);
		glVertex2f(min[0], max[1]);

		glVertex2f(min[0], max[1]);
		glVertex2f(max[0], max[1]);


		glVertex2f(max[0], max[1]);
		glVertex2f(max[0], min[1]);

		glVertex2f(max[0], min[1]);
		glVertex2f(min[0], min[1]);
	glEnd();
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);

	if(hasChildren&&currentNumItems>0) {
		nodes[0].drawNode();
		nodes[1].drawNode();
		nodes[2].drawNode();
		nodes[3].drawNode();
	}
}

void CQuadtree::drawOptimizedNode() {

	if(currentNumItems>MAX_IN_NODE) {
		glPushMatrix();
		glLoadIdentity();
		glDisable(GL_TEXTURE_2D);
		glColor3f(1,1,1);
		glBegin(GL_LINES);

			glVertex2f(min[0], min[1]);
			glVertex2f(min[0], max[1]);

			glVertex2f(min[0], max[1]);
			glVertex2f(max[0], max[1]);


			glVertex2f(max[0], max[1]);
			glVertex2f(max[0], min[1]);

			glVertex2f(max[0], min[1]);
			glVertex2f(min[0], min[1]);
		glEnd();
		glPopMatrix();
		glEnable(GL_TEXTURE_2D);
	}

	if(hasChildren&&currentNumItems>MAX_IN_NODE) {
		nodes[0].drawOptimizedNode();
		nodes[1].drawOptimizedNode();
		nodes[2].drawOptimizedNode();
		nodes[3].drawOptimizedNode();
	}
}

void CQuadtree::destroyTree() {
	currentNumItems = 0;
	if(hasChildren) {
		nodes[0].destroyTree();
		nodes[1].destroyTree();
		nodes[2].destroyTree();
		nodes[3].destroyTree();
	}
}

bool squareInNode(CMath::vec4f min, CMath::vec4f max, CMath::vec4f point, float r) {
	float mX = point[0] - r, mY = point[1] - r, dX = point[0] + r, dY = point[1] + r;
	
	return (( min[0] <= mX && max[0] >= mX  && min[1] <= mY && max[1] >= mY) ||
		    ( min[0] <= mX && max[0] >= mX  && min[1] <= dY && max[1] >= dY) ||
		    ( min[0] <= dX && max[0] >= dX  && min[1] <= dY && max[1] >= dY) ||
		    ( min[0] <= dX && max[0] >= dX  && min[1] <= mY && max[1] >= mY));
}

void CQuadtree::insertNode(int n, CMath::vec4f point, float r) {
	if (squareInNode(min, max, point, r)) {
		inNode.items[currentNumItems] = n;
		currentNumItems += 1;

		if (currentNumItems >= inNode.numItems) {
			int *tmp = inNode.items;
			inNode.items = new int [inNode.numItems*2];
			
			for(int i=0; i<currentNumItems; i+=1) {
				inNode.items[i] = tmp[i];
			}

			inNode.numItems *= 2;	
			delete [] tmp;
		}

		if (hasChildren) {
			nodes[0].insertNode(n,point,r);
			nodes[1].insertNode(n,point,r);
			nodes[2].insertNode(n,point,r);
			nodes[3].insertNode(n,point,r);
		}
	}
}

void CQuadtree::getNodes(std::vector<items> &cols) {
	if(!hasChildren || currentNumItems <= MAX_IN_NODE) {
		items tmp;
		tmp.numItems = currentNumItems;
		tmp.items = inNode.items;

		cols.push_back(tmp);
	} else if (hasChildren&&currentNumItems>MAX_IN_NODE) {
		nodes[0].getNodes(cols);
		nodes[1].getNodes(cols);
		nodes[2].getNodes(cols);
		nodes[3].getNodes(cols);
	}
}

	

std::vector<items> CQuadtree::getNodeData() {
	std::vector<items> tmp;
	getNodes(tmp);
	return tmp;
}
