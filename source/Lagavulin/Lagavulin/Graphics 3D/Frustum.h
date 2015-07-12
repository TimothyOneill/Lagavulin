#pragma once
#include "math.h"
#include "Plane.h"
#include "../Math/Vector3.h"

/**
Author: Tim O'Neill 11/07/2015
Frustrum Class
**/

class Frustrum
{
public:
    enum Side { Near, Far, Top, Right, Bottom, Left, NumPlanes };

    Plane m_Planes[NumPlanes];  //Planes of the frustrum
    Vector3 m_NearClip[4];      //Verts of the near clip plane in camera space
    Vector3 m_FarClip[4];       //Verts of the far clip plane in camera space

    float m_Fov;                //Field of view in radians
    float m_Aspect;             //Aspect ratio - width divided by height
    float m_Near;               //Near clipping distance
    float m_Far;                //Far clipping distance

Frustrum();

bool Inside (const Vector3 &point) const;
bool Inside (const Vector3 &point, const float radius) const;

const Plane &Get(Side side) { return m_Planes[side]; }

void SetFOV(float fov) { m_Fov = fov; Init(m_Fov, m_Aspect, m_Near, m_Far); }
void SetAspect(float aspect) { m_Aspect = aspect; Init(m_Fov, m_Aspect, m_Near, m_Far); }
void SetNear(float nearClip) { m_Near = nearClip; Init(m_Fov, m_Aspect, m_Near, m_Far); }
void SetFar(float farClip) { m_Far = farClip; Init(m_Fov, m_Aspect, m_Near, m_Far); }

void Init(const float fov, const float aspect, const float near, const float far);

void Render();
};