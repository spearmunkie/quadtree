#ifndef CQUADTREE_H
#define CQUADTREE_H

#include "CMath.h"
#include <vector>
#include <GL/gl.h>
struct items {
	int numItems, *items;
};

class CQuadtree {
	public:
		CQuadtree();
		void buildTree(CMath::vec4f m, CMath::vec4f mx, int d);
		void destroyTree();
		void insertNode(int n, CMath::vec4f point, float r);
		void drawNode();
		void drawOptimizedNode ();
		std::vector<items> getNodeData();
	private:
		CQuadtree *nodes;
		bool hasChildren;
		void getNodes(std::vector<items> &colls);
		int depth, currentNumItems; 
		items inNode;
		CMath::vec4f min, max;
};

#endif
