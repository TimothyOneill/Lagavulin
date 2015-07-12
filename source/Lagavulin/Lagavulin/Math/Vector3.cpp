#include "../main/stdafx.h"
#include "Vector3.h"

//Overload the Assignment Operator
Vector3 &Vector3::operator =(const Vector3 &a)
{
    x = a.x;
    y = a.y;
    z = a.z;
    return *this;
}

//Check for equality between 2 vectors
bool Vector3::operator ==(const Vector3 &a) const
{
    return x==a.x && y==a.y && z==a.z;
}
//Check if two vectors are not equal
bool Vector3::operator !=(const Vector3 &a) const
{
    return x!=a.x && y!=a.y && z!=a.z;
}

//Set the Vector to a 0 vector
void Vector3::zero()
{
    x = y = z = 0.0f;
}

//Negate the values of the vector
Vector3 Vector3::operator -() const
{
    return Vector3(-x,-y,-z);
}

//Add the values of 2 vectors together return as a new vector (communative)
Vector3 Vector3::operator +(const Vector3 &a) const
{
    return Vector3(x + a.x, y + a.y, z + a.z);
}

//Subtract the values of 2 vectors return as a new vector(NON communative)
Vector3 Vector3::operator -(const Vector3 &a) const
{
    return Vector3(x - a.x, y - a.y, z - a.z);
}
//Multiplication by a scaler returns a Vector3
Vector3 Vector3::operator *(const float &a) const
{
    return Vector3(x*a,y*a,z*a);
}

//Division by a scaler return a vector 3
Vector3 Vector3::operator /(const float &a) const
{
	float OneOverA = 1.0f/a; //NOTE No divide by 0 check
	return Vector3 (x*OneOverA,y*OneOverA,z*OneOverA);
}

//+= operator
Vector3 &Vector3::operator +=(const Vector3 &a)
{
    x += a.x;
    y += a.y;
    z += a.z;
    return *this;
}
//-= operator
Vector3 &Vector3::operator -=(const Vector3 &a)
{
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return *this;
}
//*= operator
Vector3 &Vector3::operator *=(float a)
{
    x *= a;
    y *= a;
    z *= a;
    return *this;
}
///= operator
Vector3 &Vector3::operator /=(float a)
{
    float OneOverA  = 1.0f/a;
    x *= OneOverA;
    y *= OneOverA;
    z *= OneOverA;

    return *this;
}

//overload * operator dot product
float Vector3::operator *(const Vector3 &a) const
{
    return DirectX::XMVectorGetX(DirectX::XMVector3Dot(DirectX::XMLoadFloat3(this),DirectX::XMLoadFloat3(this)));
}

