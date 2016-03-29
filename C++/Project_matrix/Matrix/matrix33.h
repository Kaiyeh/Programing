#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"
class matrix33
{
public:
	vector3 x, y, z;
public:
    matrix33(){};
	matrix33(vector3 inX, vector3 inY, vector3 inZ);
    matrix33(const matrix33 &v);
    matrix33 invert();
    matrix33 identity();

public:
	/* Operators */
	vector3               &operator [] (unsigned int index);
	const vector3         &operator [] (unsigned int index) const;

	matrix33              &operator =  (const matrix33 &v);
	matrix33              &operator += (const matrix33 &v);
	matrix33              &operator -= (const matrix33 &v);
	matrix33              &operator *= (float f);
	matrix33              &operator *= (const matrix33 &v);
	matrix33              &operator /= (float f);

	friend bool           operator == (const matrix33 &a, const matrix33 &b);
	friend bool           operator != (const matrix33 &a, const matrix33 &b);
	friend matrix33       operator - (const matrix33 &a);
	friend matrix33       operator + (const matrix33 &a, const matrix33 &b);
	friend matrix33       operator - (const matrix33 &a, const matrix33 &b);
	friend matrix33       operator * (const matrix33 &v, float f);
	friend matrix33       operator * (float f, const matrix33 &v);
	friend matrix33       operator * (const matrix33 &a, const matrix33 &b);
	friend matrix33       operator / (const matrix33 &v, float f);
public:
    void printMatrix() const;
    float determinant() const;
};

#endif
