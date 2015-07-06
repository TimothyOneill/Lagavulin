#include "stdafx.h"
#include "Vector4.h"

//Overload the Assignment Operator
Vector4 &Vector4::operator =(const Vector4 &a)
{
    x = a.x;
    y = a.y;
    z = a.z;
    w = a.w;
    return *this;
}

//Check for equality between 2 vectors
bool Vector4::operator ==(const Vector4 &a) const
{
    return x==a.x && y==a.y && z==a.z && w==a.w;
}
//Check if two vectors are not equal
bool Vector4::operator !=(const Vector4 &a) const
{
    return x!=a.x && y!=a.y && z!=a.z && w!=a.w;
}

//Set the Vector to a 0 vector
void Vector4::zero()
{
    x = y = z = w = 0.0f;
}

//Negate the values of the vector
Vector4 Vector4::operator -() const
{
    return Vector4(-x,-y,-z,-w);
}

//Add the values of 2 vectors together return as a new vector (communative)
Vector4 Vector4::operator +(const Vector4 &a) const
{
    return Vector4(x + a.x, y + a.y, z + a.z, w + a.w);
}

//Subtract the values of 2 vectors return as a new vector(NON communative)
Vector4 Vector4::operator -(const Vector4 &a) const
{
    return Vector4(x - a.x, y - a.y, z - a.z, w - a.z);
}
//Multiplication by a scaler returns a Vector4
Vector4 Vector4::operator *(const float &a) const
{
    return Vector4(x*a,y*a,z*a,w*a);
}

//Division by a scaler return a vector 3
Vector4 Vector4::operator /(const float &a) const
{
	float OneOverA = 1.0f/a; //NOTE No divide by 0 check
	return Vector4 (x*OneOverA,y*OneOverA,z*OneOverA,w*OneOverA);
}

//+= operator
Vector4 &Vector4::operator +=(const Vector4 &a)
{
    x += a.x;
    y += a.y;
    z += a.z;
    w += a.w;
    return *this;
}
//-= operator
Vector4 &Vector4::operator -=(const Vector4 &a)
{
    x -= a.x;
    y -= a.y;
    z -= a.z;
    w -= a.w;
    return *this;
}
//*= operator
Vector4 &Vector4::operator *=(float a)
{
    x *= a;
    y *= a;
    z *= a;
    w *= a;
    return *this;
}
///= operator
Vector4 &Vector4::operator /=(float a)
{
    float OneOverA  = 1.0f/a;
    x *= OneOverA;
    y *= OneOverA;
    z *= OneOverA;
    w *= OneOverA;

    return *this;
}

//overload * operator dot product
float Vector4::operator *(const Vector4 &a) const
{
    return DirectX::XMVectorGetX(DirectX::XMVector4Dot(DirectX::XMLoadFloat4(this),DirectX::XMLoadFloat4(this)));
}