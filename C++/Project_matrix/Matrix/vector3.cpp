#include "vector3.h"
#include<math.h>
#include<iostream>
using namespace std;
vector3::vector3(float xIn,float yIn,float zIn){
x=xIn;
y=yIn;
z=zIn;
}
vector3::vector3(const vector3 &v){
x=v.x;
y=v.y;
z=v.z;
}
void vector3::set(float xIn, float yIn, float zIn){
x=xIn;
y=yIn;
z=zIn;
}
float vector3::length() const{
return sqrt(x*x+y*y+z*z);
}
void vector3::printVector3() const{
cout << x << ' ' << y << ' ' << z << ' ' << endl;
}
float &vector3::operator [] (unsigned int index){
if(index==0)
    return x;
else if(index==1)
    return y;
else
    return z;
}
const float &vector3::operator [] (unsigned int index) const{
if(index==0)
    return x;
else if(index==1)
    return y;
else
    return z;
}
vector3 &vector3::operator = (const vector3 &v){
x=v.x;
y=v.y;
z=v.z;
return *this;
}
vector3 &vector3::operator += (const vector3 &v){
x+=v.x;
y+=v.y;
z+=v.z;
return *this;
}
vector3 &vector3::operator -= (const vector3 &v){
x-=v.x;
y-=v.y;
z-=v.z;
return *this;
}
vector3 &vector3::operator *= (float f){
x*=f;
y*=f;
z*=f;
return *this;
}
vector3 &vector3::operator /= (float f){
x/=f;
y/=f;
z/=f;
return *this;
}
bool operator == (const vector3 &a, const vector3 &b){
return (a.x==b.x&&a.y==b.y&&a.z==b.z?1:0);
}
bool operator != (const vector3 &a, const vector3 &b){
return !(a==b);
}

static vector3 tmp;
vector3 operator - (const vector3 &a){
static vector3 tmp;
tmp.x=-(a.x);
tmp.y=-(a.y);
tmp.z=-(a.z);
return tmp;
}

vector3 operator + (const vector3 &a, const vector3 &b){
static vector3 tmp;
tmp.x=a.x+b.x;
tmp.y=a.y+b.y;
tmp.z=a.z+b.z;
return tmp;
}
vector3 operator - (const vector3 &a, const vector3 &b){
static vector3 tmp;
tmp.x=a.x-b.x;
tmp.y=a.y-b.y;
tmp.z=a.z-b.z;
return tmp;
}

vector3 operator * (const vector3 &v, float f){
static vector3 tmp;
tmp.x=v.x*f;
tmp.y=v.y*f;
tmp.z=v.z*f;
return tmp;
}
vector3 operator * (float f, const vector3 &v){
static vector3 tmp;
tmp.x=v.x*f;
tmp.y=v.y*f;
tmp.z=v.z*f;
return tmp;
}
vector3 operator / (const vector3 &v, float f){
static vector3 tmp;
tmp.x=v.x/f;
tmp.y=v.y/f;
tmp.z=v.z/f;
return tmp;
}
