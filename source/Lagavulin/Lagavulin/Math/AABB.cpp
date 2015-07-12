#include "../main/stdafx.h"
#include "AABB.h"

Vector4 AABB::corner(int i) const
{
    assert(i >= 0.);
    assert(i <= 7);

    return Vector4(
        (i & 1) ? max.x : min.x,
        (i & 2) ? max.y : min.y,
        (i & 4) ? max.z : min.z,
        1.0f
    );
}

void AABB::empty()
{
    const float kBigNumber = 1e37f;
    min.x = min.y = min.z = kBigNumber;
    max.x = max.y = max.z = -kBigNumber;
}

void AABB::add(const Vector4 &p)
{
    //expand the box as necessary to contain the point.

    if (p.x < min.x) min.x  = p.x;
    if (p.x > max.x) max.x  = p.x;
    if (p.y < min.x) min.y  = p.y;
    if (p.y > max.x) max.y  = p.y;
    if (p.z < min.x) min.z  = p.z;
    if (p.z > max.x) max.z  = p.z;
}

void AABB::add(const AABB &box)
{
    //expand the box as necessary

    if (box.min.x < min.x) min.x  = box.min.x;
    if (box.min.x > min.x) min.x  = box.min.x;
    if (box.min.y < min.x) min.y  = box.min.y;
    if (box.min.y > min.x) min.y  = box.min.y;
    if (box.min.z < min.x) min.z  = box.min.z;
    if (box.min.z > min.x) min.z  = box.min.z;
}

void AABB::setToTransformedbox(const AABB &box, const Matrix4x4 &m)
{
    if (box.isEmpty())
    {
        empty();
        return;
    }

    //Start with translation
    Vector3 translation(m.GetPosition());
    //min = max = translation;

    if (m._11 > 0.0f)
    {
        
    }
}

bool AABB::isEmpty() const
{
    return (min.x > max.x) || (min.y > max.y) || (min.z > max.z);
}

bool AABB::contains(const Vector4 &p) const
{
    return (p.x >= min.x) && (p.x <= max.x) && (p.y >= min.y) && (p.y <= max.y) && (p.z >= min.z) && (p.z <= max.z);
}

Vector4 AABB::closestPointTo(const Vector4 &p) const
{
    Vector4 vOut;

    if (p.x < min.x)
	{
		vOut.x = min.x;
	}
	else if (p.x > max.x)
	{
		vOut.x = max.x;
	}
	else
	{
		vOut.x = p.x;
	}

	if (p.y < min.y)
	{
		vOut.y = min.y;
	}
	else if (p.y > max.y)
	{
		vOut.y = max.y;
	}
	else
	{
		vOut.y = p.y;
	}

	if (p.z < min.z)
	{
		vOut.z = min.z;
	}
	else if (p.z > max.z)
	{
		vOut.z = max.z;
	}
	else
	{
		vOut.z = p.z;
	}

    return vOut;
}

bool AABB::intersectsSphere(const Vector4 &center, float radius) const
{
    //Vector4 closestPointTo = closestPointTo(center);
    //return distanceSquared(center, closestPoint) < radius*radius;

    return true;
}

float AABB::rayIntersect(const Vector4 &rayORg, const Vector4 &rayDelta, Vector4 *returnNormal) const
{
    return -1.0f;
}

int AABB::classifyPlane(const Vector4 &n, float d) const
{
    return -1;
}

float AABB::intersectsPlane(const Vector4 &n, float planeD, const Vector4 &dir) const
{
    return -1.0f;
}