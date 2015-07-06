#pragma once
#include "math.h"
#include "DirectXMath.h"

/**
Author: Tim O'Neill 14/02/2015
Simple Vector3 class based on 3D math primer.
**/

class Vector3 : public DirectX::XMFLOAT3
{
public:

    //Copy Constructor to copy 1 XMFLOAT3 into are wrapper.
    Vector3(XMFLOAT3 &a) : x(a.x), y(a.y), z(a.z) {};
    //Default Constructor intializes to 0
    Vector3() : XMFLOAT3() { x = 0; y = 0; z = 0; };
    //Overloaded constructor for set values.
    Vector3(const float x,const float y,const float z) : x(x), y(y), z(z) {};
    //Copy Constructor for vector4 into a vector3
    //TODO: Vector4 implementation.
    //Vector3(const class Vector4 &a) : x(a.x), y(a.y), z(a.z) {};

    //Overload the Assignment Operator
    Vector3 &operator =(const Vector3 &a);

    //Check for equality between 2 vectors
    bool operator ==(const Vector3 &a) const;

    //Check if two vectors are not equal
    bool operator !=(const Vector3 &a) const;

    //Set the Vector to a 0 vector
    void zero();

    //Negate the values of the vector
    Vector3 operator -() const;

    //Add the values of 2 vectors together return as a new vector (communative)
    Vector3 operator +(const Vector3 &a) const;

    //Subtract the values of 2 vectors return as a new vector(NON communative)
    Vector3 operator -(const Vector3 &a) const;

    //Multiplication by a scaler returns a Vector3
    Vector3 operator *(const float &a) const;

    //Division by a scaler return a vector 3
    Vector3 operator /(const float &a) const;

    //+= operator
    Vector3 &operator +=(const Vector3 &a);

    //-= operator
    Vector3 &operator -=(const Vector3 &a);

    //*= operator
    Vector3 &operator *=(float a);

    ///= operator
    Vector3 &operator /=(float a);

    //overload * operator dot product
    float operator *(const Vector3 &a) const;

    //normalize
    inline Vector3* Normalize()
    {
        DirectX::XMStoreFloat3(this, DirectX::XMVector3Normalize(DirectX::XMLoadFloat3(this)));
        return this;
    }

    //Get the Magnitude of the vector
    inline float Magnitude()
    {
        return DirectX::XMVectorGetX(DirectX::XMVector3Length(DirectX::XMLoadFloat3(this)));
    }

    //Get the cross product of b against this
    inline Vector3 CrossProduct(const Vector3 &b) const
    {
        Vector3* Out;
        DirectX::XMStoreFloat3(Out,DirectX::XMVector3Cross(DirectX::XMLoadFloat3(this), DirectX::XMLoadFloat3(&b)));
        return *Out;
    }

    float x, y, z;
};

//scaler on left multiplication
inline Vector3 operator *(float k, const Vector3 &a) 
{
    return Vector3(k*a.x, k*a.y, k*a.z);
}
//distance between 2 points
float Distance(Vector3 &a, Vector3 &b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float dz = a.z - a.z;

    return sqrt(dx*dx + dy*dy + dz*dz);
}