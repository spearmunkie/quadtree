#ifndef CIMAGE_H
#define CIMAGE_H

#include <GL/gl.h>
#include <IL/il.h>
class CImage {

	public:
		GLuint load(char * file);
	private:
		ILuint texid;
		GLuint glimage;
};

#endif
