#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <math.h>

class VECTOR
{
public:
	float x,y,z;

	VECTOR()
	{
		x=0.0f;
		y=0.0f;
		z=0.0f;
	}

	VECTOR(const float* v)
	{
		x=v[0];
		y=v[1];
		z=v[2];
	}

	VECTOR(const float* p1,const float* p2)
	{
		x=p2[0]-p1[0];
		y=p2[1]-p1[1];
		z=p2[2]-p1[2];
	}

	void normalizer()
	{
		float len;
		len = sqrt(x*x + y*y + z*z);
		x = x/len;
		y = y/len;
		z = z/len;
	}
};

void Cross_Product(const VECTOR& v1,const VECTOR& v2,VECTOR& ans)
{
	// a¡¿b=(a2b3 - a3b2, a3b1 - a1b3, a1b2 - a2b1)
	ans.x = v1.y * v2.z - v1.z * v2.y;
	ans.y = v1.z * v2.x - v1.x * v2.z;
	ans.z = v1.x * v2.y - v1.y * v2.x;
}



#endif