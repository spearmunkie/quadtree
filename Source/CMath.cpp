#include "CMath.h"

#define DEBUG CDebug<<"CMath: "

namespace CMath {
	int randInt(int min,int max) {
    	return  (rand()%(int)(max-min+1)+min);
   	}
   
   	float randFloat(float min,float max) {
   		if (min==max)
        	return min;
      	return ( (float)(randInt( (int)min, (int)max - 1)) + ((float)rand() / ((float)RAND_MAX + 1)));
   	}
   
   	float getAngle(float x1, float  y1, float x2, float y2) {
    	float opp = y2 - y1;
    	float adj = x2 - x1;
    	if (adj == 0)
        	if (y2 > y1)
            	return 270;
        	else
            	return 90;
    	else if (opp >= 0 && adj > 0)
        	return 360 - atan  (opp / adj)*DEG_TO_RAD;
    	else if (adj < 0)
        	return 180-atan  (opp / adj)*DEG_TO_RAD;
    	else if (opp < 0 && adj > 0)
        	return 360-atan  (opp / adj)*DEG_TO_RAD;
    	return 0;
	}

	float distance(float x1,float y1,float x2,float y2) {
    	return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
	}

	float distance(vec4f v1,vec4f v2) {
		return distance(v1[0],v1[1], v2[0],v2[1]);
	}
	
	float getAngle(vec4f v1,vec4f v2) {
		return getAngle(v1[0],v1[1], v2[0],v2[1]);
	}

	float cosd (float angle) {
		return cos(angle*DEG_TO_RAD);
	}

	float sind (float angle) {
		return sin(angle*DEG_TO_RAD);
	}

	vec4f::vec4f (float x, float y, float z) {
		v[0] = x;
		v[1] = y;
		v[2] = z;
		v[3] = 1;
	}

	
	vec4f::vec4f(float vec[3]) {
		v[0] = vec[0];
		v[1] = vec[1];
		v[2] = vec[2];
		v[3] = 1;
	}

	float& vec4f::operator[] (int n) {
		return v[n];
	}

	float vec4f::operator[] (int n) const {
		return v[n];
	}

	void vec4f::operator= (const vec4f v2) {
		v[0] = v2[0];
		v[1] = v2[1];
		v[2] = v2[2];
		v[3] = 1;
	}

	vec4f vec4f::operator* (float scalar) {
		return vec4f(v[0]*scalar, v[1]*scalar, v[2]*scalar);
	}

	vec4f vec4f::operator/ (float scalar) {
		return vec4f(v[0]/scalar, v[1]/scalar, v[2]/scalar);
	}

	vec4f vec4f::operator+ (const vec4f v2) {
		return vec4f(v[0] + v2[0], v[1] + v2[1], v[2] + v2[2]);
	}

	vec4f vec4f::operator- (const vec4f v2) {
		return vec4f(v[0] - v2[0], v[1] - v2[1], v[2] - v2[2]);
	}

	vec4f vec4f::operator- () {
		return vec4f(v[0]*-1, v[1]*-1, v[2]*-1);
	}

	void vec4f::operator*= (float scalar) {
		v[0] *= scalar;
		v[1] *= scalar;
		v[2] *= scalar;
		v[3] = 1;
	}

	void vec4f::operator/= (float scalar) {
		v[0] /= scalar;
		v[1] /= scalar;
		v[2] /= scalar;
		v[3] = 1;
	}


	void vec4f::operator+= (const vec4f v2) {
		v[0] += v2[0];
		v[1] += v2[1];
		v[2] += v2[2];
		v[3] = 1;
	}
	void vec4f::operator-= (const vec4f v2) {
		v[0] -= v2[0];
		v[1] -= v2[1];
		v[2] -= v2[2];
		v[3] = 1;
	}

	float vec4f::dot2f (const vec4f v2) {
		return v[0]*v2[0] + v[1]*v2[1];
	}
	
	float vec4f::dot3f (const vec4f v2) {
		return v[0]*v2[0] + v[1]*v2[1] + v[2]*v2[2];
	}

	vec4f vec4f::cross (const vec4f v2) {
		return vec4f(v[1] * v2[2] - v[2] * v2[1],
				v[2] * v2[0] - v[0] * v2[2],
				v[0] * v2[1] - v[1] * v2[0]);
	}

	void vec4f::norm2f() {
		float mag = sqrt(v[0]*v[0] + v[1]*v[1]);
		v[0] /= mag;
		v[1] /= mag;
	}

	void vec4f::norm3f() {
		float mag = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
		v[0] /=mag;
		v[1] /= mag;
		v[2] /= mag;
	}

	mat4f4::mat4f4 (const mat4f4 &m2) {
		for(int i = 0; i < 16; i++) {
			m[i] = m2[i];
		}
	}

	mat4f4::mat4f4 (float *m2) {
		for(int i = 0; i < 16; i++) {
			DEBUG<<i<<":";
			CDebug.flush();
			m[i] = m2[i];


			DEBUG<<m[i]<<"\n";
			CDebug.flush();
		}
	}

	mat4f4::mat4f4() {
		for (int i=0;i<16; i+=1) {
			m[i] = 0;
		}
	}

	float& mat4f4::operator[] (int n) {
		return m[n];
	}

	float mat4f4::operator[] (int n) const {
		return m[n];
	}

	void mat4f4::operator= (const mat4f4 m2) {
		for(int i = 0; i < 16; i+=1) {
			m[i] = m2[i];
		}
	}
	
	void mat4f4::operator= (float *m2) {
		for(int i = 0; i < 16; i+=1) {
			m[i] = m2[i];
		}
	}

	mat4f4 mat4f4::operator* (float scalar) {
		float m2[16];
		for(int i = 0; i < 16; i+=1) {
			DEBUG<<i<<"\n";
			CDebug.flush();
			m2[i] = m[i]*scalar;
		}
		return mat4f4(m2);
	}

	mat4f4 mat4f4::operator/ (float scalar) {
		float m2[16];
		for(int i = 0; i < 16; i+=1) {
			m2[i] = m[i]/scalar;
		}

		return mat4f4(m2);
	}

	mat4f4 mat4f4::operator* (const mat4f4 m2) {
		float m3[16];
		for(int i = 0; i < 16; i+=1) {
			int r = i%4;
			int p = floor(i/4) * 4;
			m3[i] = m[r]*m2[p] + m[r+4]*m2[p+1] + m[r+8]*m2[p+2] + m[r+12]*m2[p+3];
		}
		return mat4f4(m3);
	}

	vec4f mat4f4::operator* (const vec4f v) {
		vec4f v2;
		for(int i = 0; i < 4; i+=1) {
			int r = i%4;
			int p = floor(i/4) * 4;
			v2[i] = m[i]*v[0] + m[i+4]*v[1] + m[i+8]*v[2] + m[i+12]*v[3];
		}
		v2[3] = 1;
		return v2;
	}

	mat4f4 mat4f4::operator+ (const mat4f4 m2) {
		float m3[16];
		for(int i = 0; i<16; i+=1) {
			m3[i] = m[i] + m2[i];
		}

		return mat4f4(m3);
	}

	mat4f4 mat4f4::operator- (const mat4f4 m2) {
		float m3[16];
		for(int i = 0; i<16; i+=1) {
			m3[i] = m[i] - m2[i];
		}

		return mat4f4(m3);
	}

	mat4f4 mat4f4::operator- () {
		float m3[16];
		for(int i = 0; i<16; i+=1) {
			m3[i] = m[i]*-1;
		}

		return mat4f4(m3);
	}

	void mat4f4::operator+= (const mat4f4 m2) {
		for(int i=0; i<16; i+=1) {
			m[i] += m2[i];
		}
	}

	void mat4f4::operator-= (const mat4f4 m2) {
		for(int i=0; i<16; i+=1) {
			m[i] -= m2[i];
		}
	}
	void mat4f4::operator*= (float scalar) {
		for(int i=0; i<16; i+=1) {
			m[i] *= scalar;
		}
	}
	void mat4f4::operator*= (const mat4f4 m2) {
		(*this) = (*this) * m2;
	}

	void mat4f4::operator/= (float scalar) {
		for(int i=0; i<16; i+=1) {
			m[i] /= scalar;
		}
	}
}


std::ostream& operator<<(std::ostream &output, const CMath::vec4f &vec) {
	output<<"("<<vec[0]<<","<<vec[1]<<","<<vec[2]<<")";

	return output;
}

std::ostream& operator<<(std::ostream &output, const CMath::mat4f4 &mat) {
	for (int i=0; i<4; i+=1) {
		output<<mat[i]<<" "<<mat[i+4]<<" "<<mat[i+8]<<" "<<mat[i+12]<<"\n";
	}

	return output;
}

