#include "CDebug.h"
#include "CMath.h"
#include <iostream>

std::ofstream CDebug("debug.txt");
#define DEBUG_MODE
int main () {
	std::cout<<"CONSTRUCTOR\n";
	CMath::vec4f a(0,1,2);
	std::cout<<a<<"\n";
	
	std::cout<<"ACCESS\n";
	a[0] = 4;
	a[1] = 5;
	a[2] = 6;
	std::cout<<a<<"\n";

	std::cout<<"DISTANCE\n";
	CMath::vec4f v1(0,0,0), v2(3,4);
	std::cout<<CMath::distance(v1,v2)<<"\n"<<CMath::distance(v2, v1)<<"\n";
	
	std::cout<<"EQUALITY\n";
	v2 = CMath::vec4f(-1,1);
	std::cout<<v2<<"\n"<<v1<<"\n";

	std::cout<<"GET ANGLE\n";
	std::cout<<getAngle(v1,v2)<<"\n";
	v2 = CMath::vec4f(1,1);
	std::cout<<getAngle(v1,v2)<<"\n";
	v2 = CMath::vec4f(-1,-1);
	std::cout<<getAngle(v1,v2)<<"\n";
	v2 = CMath::vec4f(1,-1);
	std::cout<<getAngle(v1,v2)<<"\n";

	std::cout<<"DEGREE TRIG\n";
	std::cout<<CMath::cosd(0)<<"\n";
	std::cout<<CMath::sind(0)<<"\n";

	std::cout<<"BASIC OPPS\n";
	std::cout<<CMath::vec4f(2,4,6)*0.5<<"\n";
	std::cout<<CMath::vec4f(2,4,6)/2<<"\n";
	std::cout<<CMath::vec4f(1,2,3) + CMath::vec4f(4,5,6)<<"\n";
	std::cout<<CMath::vec4f(1,2,3) - CMath::vec4f(1,2,3)<<"\n";
	std::cout<<-CMath::vec4f(1,2,3)<<"\n";

	std::cout<<"INCREMENT OPPS\n";
	v1 = CMath::vec4f(1,2,3);
	v2 = CMath::vec4f(4,5,6);

	v1+=v2;
	std::cout<<v1<<"\n";

	v1-=v2;
	std::cout<<v1<<"\n";

	v1*=2;
	std::cout<<v1<<"\n";

	v1/=2;
	std::cout<<v1<<"\n";

	CMath::mat4f4 A,B;
	
	std::cout<<"MAT4F4 CONSTUCT\n";
	A[0] = 1; A[4] = 2; A[8] = 3; A[12] = 4;
	A[1] = 5; A[5] = 6; A[9] = 7; A[13] = 8;
	A[2] = 9; A[6] = 10; A[10] = 11; A[14] = 12;
	A[3] = 13; A[7] = 14; A[11] = 15; A[15] = 16;

	std::cout<<A;
	
	std::cout<<"MAT4F4 CONSTUCT\n";
	B[0] = 0; B[4] = 4; B[8] = 8; B[12] = 12;
	B[1] = 1; B[5] = 5; B[9] = 9; B[13] = 13;
	B[2] = 2; B[6] = 6; B[10] = 10; B[14] = 14;
	B[3] = 3; B[7] = 7; B[11] = 11; B[15] = 15;

	std::cout<<B;


	std::cout<<"MAT4F4 MULT\n";
	std::cout<<A*B<<"\n";
	std::cout<<B*2<<"\n"<<B/2<<"\n";
	std::cout<<"MAT VEC MULT "<<A*CMath::vec4f(0, 1, 2)<<"\n";

	std::cout<<"MAT4F4 OPPS\n";
	std::cout<<A+B<<"\n"<<A-B<<"\n"<<-A;

	std::cout<<"MAT4F4 INC OPPS\n";
	A+=B;
	std::cout<<A<<"\n";

	A-=B;
	std::cout<<A<<"\n";
	
	A*=2;
	std::cout<<A<<"\n";

	A/=2;
	std::cout<<A<<"\n";

	A*=B;
	std::cout<<A<<"\n";

	return 0;
}

