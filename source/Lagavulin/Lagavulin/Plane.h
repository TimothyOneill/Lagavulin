#pragma once
#include "math.h"
#include "Vector3.h"
#include "DirectXMath.h"

/**
Author: Tim O'Neill 08/07/2015
Plane Class implementation wrapper
**/

class Plane : public DirectX::XMFLOAT4
{
public:
    inline void Normalize();

    inline void Init(const Vector3 &p0, const Vector3 &p1, const Vector3 &p2);
    bool Inside(const Vector3 &point, const float radius) const;
    bool Inside(const Vector3 &point) const;
};

inline void Plane::Normalize()
{
    float mag;
    mag = sqrt(x * x + y * y + z * z);
    x = x / mag;
    y = y / mag;
    z = z / mag;
    w = w / mag;
}

inline void Plane::Init(const Vector3 &p0, const Vector3 &p1, const Vector3 &p2)
{
    DirectX::XMStoreFloat4(this, DirectX::XMPlaneFromPoints(DirectX::XMLoadFloat3(&p0),DirectX::XMLoadFloat3(&p1),DirectX::XMLoadFloat3(&p2)));
    Normalize();
}