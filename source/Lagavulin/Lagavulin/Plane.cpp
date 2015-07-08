#include "stdafx.h"
#include "Plane.h"

bool Plane::Inside(const Vector3 &point) const
{
    float result = DirectX::XMVectorGetX(DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(this),DirectX::XMLoadFloat3(&point)));
    return (result >= 0.0f);
}

bool Plane::Inside(const Vector3 &point, const float radius) const
{
    float fdistance;

    fdistance = DirectX::XMVectorGetX(DirectX::XMPlaneDotCoord(DirectX::XMLoadFloat4(this),DirectX::XMLoadFloat3(&point)));

    return (fdistance >= -radius);
}