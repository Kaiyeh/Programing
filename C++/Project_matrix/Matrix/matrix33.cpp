#include "matrix33.h"
#include<math.h>
#include<iostream>
using namespace std;
matrix33::matrix33(vector3 inX, vector3 inY, vector3 inZ){
x=inX;
y=inY;
z=inZ;
}
matrix33::matrix33(const matrix33 &v){
x=v.x;
y=v.y;
z=v.z;
}

vector3 &matrix33::operator [] (unsigned int index){
if(index==0)
    return x;
else if(index==1)
    return y;
else
    return z;
}
const vector3 &matrix33::operator [] (unsigned int index) const{
if(index==0)
    return x;
else if(index==1)
    return y;
else
    return z;
}
matrix33 &matrix33::operator = (const matrix33 &v){
this->x=v.x;
this->y=v.y;
this->z=v.z;
return *this;
}
matrix33 &matrix33::operator += (const matrix33 &v){
this->x+=v.x;
this->y+=v.y;
this->z+=v.z;
return *this;
}
matrix33 &matrix33::operator -= (const matrix33 &v){
this->x-=v.x;
this->y-=v.y;
this->z-=v.z;
return *this;
}
matrix33 &matrix33::operator *= (float f){
this->x*=f;
this->y*=f;
this->z*=f;
return *this;
}
matrix33 &matrix33::operator /= (float f){
this->x/=f;
this->y/=f;
this->z/=f;
return *this;
}
bool operator == (const matrix33 &a, const matrix33 &b){
return (a.x==b.x&&a.y==b.y&&a.z==b.z);
}
bool operator != (const matrix33 &a, const matrix33 &b){
return !(a==b);
}
matrix33 operator - (const matrix33 &a){
static matrix33 tmp;
tmp.x=-a.x;
tmp.y=-a.y;
tmp.z=-a.z;
return tmp;
}
matrix33 operator + (const matrix33 &a, const matrix33 &b){
static matrix33 tmp;
tmp.x=a.x+b.x;
tmp.y=a.y+b.y;
tmp.z=a.z+b.z;
return tmp;
}
matrix33 operator - (const matrix33 &a, const matrix33 &b){
static matrix33 tmp;
tmp.x=a.x-b.x;
tmp.y=a.y-b.y;
tmp.z=a.z-b.z;
return tmp;
}
matrix33 operator * (const matrix33 &v, float f){
static matrix33 tmp;
tmp.x=v.x*f;
tmp.y=v.y*f;
tmp.z=v.z*f;
return tmp;
}
matrix33 operator * (float f, const matrix33 &v){
static matrix33 tmp;
tmp.x=v.x*f;
tmp.y=v.y*f;
tmp.z=v.z*f;
return tmp;
}
matrix33 operator * (const matrix33 &a, const matrix33 &b){
static matrix33 tmp;
tmp[0][0]=a[0][0]*b[0][0]+a[1][0]*b[0][1]+a[2][0]*b[0][2];
tmp[1][0]=a[0][0]*b[1][0]+a[1][0]*b[1][1]+a[2][0]*b[1][2];
tmp[2][0]=a[0][0]*b[2][0]+a[1][0]*b[2][1]+a[2][0]*b[2][2];
tmp[0][1]=a[0][1]*b[0][0]+a[1][1]*b[0][1]+a[2][1]*b[0][2];
tmp[1][1]=a[0][1]*b[1][0]+a[1][1]*b[1][1]+a[2][1]*b[1][2];
tmp[2][1]=a[0][1]*b[2][0]+a[1][1]*b[2][1]+a[2][1]*b[2][2];
tmp[0][2]=a[0][2]*b[0][0]+a[1][2]*b[0][1]+a[2][2]*b[0][2];
tmp[1][2]=a[0][2]*b[1][0]+a[1][2]*b[1][1]+a[2][2]*b[1][2];
tmp[2][2]=a[0][2]*b[2][0]+a[1][2]*b[2][1]+a[2][2]*b[2][2];
return tmp;
}
matrix33 &matrix33::operator *= (const matrix33 &b){
static matrix33 tmp;
tmp[0][0]=(*this)[0][0]*b[0][0]+(*this)[1][0]*b[0][1]+(*this)[2][0]*b[0][2];
tmp[1][0]=(*this)[0][0]*b[1][0]+(*this)[1][0]*b[1][1]+(*this)[2][0]*b[1][2];
tmp[2][0]=(*this)[0][0]*b[2][0]+(*this)[1][0]*b[2][1]+(*this)[2][0]*b[2][2];
tmp[0][1]=(*this)[0][1]*b[0][0]+(*this)[1][1]*b[0][1]+(*this)[2][1]*b[0][2];
tmp[1][1]=(*this)[0][1]*b[1][0]+(*this)[1][1]*b[1][1]+(*this)[2][1]*b[1][2];
tmp[2][1]=(*this)[0][1]*b[2][0]+(*this)[1][1]*b[2][1]+(*this)[2][1]*b[2][2];
tmp[0][2]=(*this)[0][2]*b[0][0]+(*this)[1][2]*b[0][1]+(*this)[2][2]*b[0][2];
tmp[1][2]=(*this)[0][2]*b[1][0]+(*this)[1][2]*b[1][1]+(*this)[2][2]*b[1][2];
tmp[2][2]=(*this)[0][2]*b[2][0]+(*this)[1][2]*b[2][1]+(*this)[2][2]*b[2][2];
return tmp;
}
matrix33 operator / (const matrix33 &v, float f){
static matrix33 tmp;
tmp.x=v.x/f;
tmp.y=v.y/f;
tmp.z=v.z/f;
return tmp;
}
float matrix33::determinant() const {
return ((*this)[0][0]*(*this)[1][1]*(*this)[2][2])+((*this)[1][0]*(*this)[2][1]*(*this)[0][2])+((*this)[2][0]*(*this)[0][1]*(*this)[1][2])-((*this)[0][2]*(*this)[1][1]*(*this)[2][0])-((*this)[1][0]*(*this)[0][1]*(*this)[2][2])-((*this)[0][0]*(*this)[1][2]*(*this)[2][1]);
}
matrix33 matrix33::identity(){
x[0]=1;
x[1]=0;
x[2]=0;
y[0]=0;
y[1]=1;
y[2]=0;
z[0]=0;
z[1]=0;
z[2]=1;
return *this;
}

matrix33 matrix33::invert(){
matrix33 tmp;
tmp[0][0]=((*this)[1][1]*(*this)[2][2])-((*this)[2][1]*(*this)[1][2]);
tmp[0][1]=-(((*this)[0][1]*(*this)[2][2])-((*this)[2][1]*(*this)[0][2]));
tmp[0][2]=((*this)[0][1]*(*this)[1][2])-((*this)[1][1]*(*this)[0][2]);
tmp[1][0]=-(((*this)[1][0]*(*this)[2][2])-((*this)[2][0]*(*this)[1][2]));
tmp[1][1]=((*this)[0][0]*(*this)[2][2])-((*this)[2][0]*(*this)[0][2]);
tmp[1][2]=-(((*this)[0][0]*(*this)[1][2])-((*this)[1][0]*(*this)[0][2]));
tmp[2][0]=((*this)[1][0]*(*this)[2][1])-((*this)[2][0]*(*this)[1][1]);
tmp[2][1]=-(((*this)[0][0]*(*this)[2][1])-((*this)[2][0]*(*this)[0][1]));
tmp[2][2]=((*this)[0][0]*(*this)[1][1])-((*this)[1][0]*(*this)[0][1]);
tmp/=(this->determinant());
x=tmp.x;
y=tmp.y;
z=tmp.z;
return *this;
}

void matrix33::printMatrix() const{
cout << (*this)[0][0] << " " << (*this)[1][0] << " " << (*this)[2][0] <<endl;
cout << (*this)[0][1] << " " << (*this)[1][1] << " " << (*this)[2][1] <<endl;
cout << (*this)[0][2] << " " << (*this)[1][2] << " " << (*this)[2][2] <<endl;
}



