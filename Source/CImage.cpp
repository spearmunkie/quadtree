#include "CImage.h"
#include <GL/gl.h>
#include "CDebug.h"
#define DEBUG CDebug<<"CImage: "
GLuint CImage::load(char* file) {
	ilGenImages(1, &texid);
  	ilBindImage(texid); 
	ilLoadImage(file);

	glGenTextures(1, &glimage); 
	glBindTexture(GL_TEXTURE_2D, glimage); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
									
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA , ilGetInteger(IL_IMAGE_WIDTH),
			ilGetInteger(IL_IMAGE_HEIGHT), 0, GL_RGBA, GL_UNSIGNED_BYTE,
			ilGetData());
	return glimage;
}
