#pragma once
#include <assert.h>
#include "Vector4.h"
#include "Matrix4x4.h"

/**
Author: Tim O'Neill 12/07/2015
Implementation of AABB
**/

//TODO: Consider using Vector3 to save a bit of memory

class AABB
{
public: 
    Vector4 min;
    Vector4 max;

    Vector4 size() const { return max - min; }
    float xSize() { return max.x - min.x; }
    float ySize() { return max.y - min.y; }
    float zSize() { return max.z - min.z; }

    Vector4 center() const { return (min + max) * 0.5f; }
    Vector4 corner(int i) const;

    void empty();
    void add(const Vector4 &p);
    void add(const AABB &box);
    void setToTransformedbox(const AABB &box, const Matrix4x4 &m);

    bool isEmpty() const;
    bool contains(const Vector4 &p) const;
    Vector4 closestPointTo(const Vector4 &p) const;
    bool intersectsSphere(const Vector4 &center, float radius) const;
    float rayIntersect(const Vector4 &rayORg, const Vector4 &rayDelta, Vector4 *returnNormal = 0) const;
    int classifyPlane(const Vector4 &n, float d) const;
    float intersectsPlane(const Vector4 &n, float planeD, const Vector4 &dir) const;
};

bool intersectAABBs(const AABB &box1, const AABB &box2, AABB *boxIntersect = 0);
float intersectMovingAABB(const AABB &stationaryBox, const AABB &movingBox, const Vector4 &d);