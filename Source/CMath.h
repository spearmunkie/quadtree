#ifndef CMATH_H
#define CMATH_H
#include <iostream>
#include "CDebug.h"
#include <cmath>
#include <cstdlib>

namespace CMath {
	struct mat4f4;
	struct vec4f {
		public:
			float v[4];

			vec4f (float x = 0, float y = 0, float z = 0);
			vec4f (float vec[3]);

			float& operator[] (int n);
			float operator[] (int n) const;

			void operator= (const vec4f v2);

			vec4f operator* (float scalar);
			vec4f operator/ (float scalar);
			vec4f operator+ (const vec4f v2);
			vec4f operator- (const vec4f v2);
			vec4f operator- ();
			
			void operator*= (float scalar);
			void operator*= (const mat4f4 m);
			void operator/= (float scalar);
			void operator+= (const vec4f v2);
			void operator-= (const vec4f v2);
			
			float dot2f (const vec4f v2);
			float dot3f (const vec4f v2);
			vec4f cross (const vec4f v2);

			void norm2f();
			void norm3f();
	};

	struct mat4f4 {
		public:
			float m[16];

			mat4f4 (const mat4f4 &m2);
			mat4f4 (float *m2);
			mat4f4 ();

			float& operator[] (int n);
			float operator[] (int n) const;
			
			void operator= (const mat4f4 m2);
			void operator= (float *m2);

			mat4f4 operator* (float scalar);
			mat4f4 operator/ (float scalar);
			mat4f4 operator* (const mat4f4 m2);
			vec4f operator* (const vec4f v);

			mat4f4 operator+ (const mat4f4 m2);
			mat4f4 operator- (const mat4f4 m2);
			mat4f4 operator- ();

			void operator+= (const mat4f4 m2);
			void operator-= (const mat4f4 m2);
			void operator*= (float scalar);
			void operator*= (const mat4f4 m);
			void operator/= (float scalar);

	};
	
	static const double DEG_TO_RAD=57.29578;
	
	float randFloat (float min,float max);

	int randInt (int min,int max);
	
	float distance (float x1,float y1,float x2,float y2);

	float distance (vec4f vec1, vec4f vec2);
	
	float getAngle (float x1, float y1, float x2, float y2);
	
	float getAngle (vec4f vec1, vec4f vec2);

	float cosd (float angle);

	float sind (float angle);
}

std::ostream& operator<<(std::ostream &output, const CMath::vec4f &vec);
std::ostream& operator<<(std::ostream &output, const CMath::mat4f4 &mat);
#endif
