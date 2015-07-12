#pragma once
#include <list>
#include "DirectXMath.h"
#include "math.h"

/**
Author: Tim O'Neill 14/02/2015
Simple Vector4 class based on 3D math primer.
**/

class Vector4 : public DirectX::XMFLOAT4
{
public:
    //Copy Constructor to copy 1 XMFLOAT4 into are wrapper.
    Vector4(XMFLOAT4 &a) { x = a.x, y = a.y, z = a.z, w = a.w; };
    //Default Constructor intializes to 0
    Vector4() : XMFLOAT4() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; };
    //Overloaded constructor for set values.
    Vector4(const float _x, const float _y, const float _z, const float _w) { x = _x, y = _y, z = _z, w = _w; };

    //Overload the Assignment Operator
    Vector4 &operator =(const Vector4 &a);

    //Check for equality between 2 vectors
    bool operator ==(const Vector4 &a) const;

    //Check if two vectors are not equal
    bool operator !=(const Vector4 &a) const;

    //Set the Vector to a 0 vector
    void zero();

    //Negate the values of the vector
    Vector4 operator -() const;

    //Add the values of 2 vectors together return as a new vector (communative)
    Vector4 operator +(const Vector4 &a) const;

    //Subtract the values of 2 vectors return as a new vector(NON communative)
    Vector4 operator -(const Vector4 &a) const;

    //Multiplication by a scaler returns a Vector4
    Vector4 operator *(const float &a) const;

    //Division by a scaler return a vector 3
    Vector4 operator /(const float &a) const;

    //+= operator
    Vector4 &operator +=(const Vector4 &a);

    //-= operator
    Vector4 &operator -=(const Vector4 &a);

    //*= operator
    Vector4 &operator *=(float a);

    ///= operator
    Vector4 &operator /=(float a);

    //overload * operator dot product
    float operator *(const Vector4 &a) const;

    //normalize
    inline Vector4* Normalize()
    {
        DirectX::XMStoreFloat4(this, DirectX::XMVector4Normalize(DirectX::XMLoadFloat4(this)));
        return this;
    }

    //Get the Magnitude of the vector
    inline float Magnitude()
    {
        return DirectX::XMVectorGetX(DirectX::XMVector4Length(DirectX::XMLoadFloat4(this)));
    }
};

typedef std::list<Vector4> Vector4List;