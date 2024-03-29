#pragma once
#include "DirectXMath.h"
#include "Matrix4x4.h"
#include "Vector3.h"

/**
Author: Tim O'Neill 08/07/2015
Quaternion Class implementation wrapper
**/

class Quaternion : public DirectX::XMFLOAT4
{
public: 
    //static const Quaternion g_Identity;

    Quaternion(XMFLOAT4 &q) : XMFLOAT4(q) {};
    Quaternion() : XMFLOAT4 () {};

    void Normalize();
    void Slerp(const Quaternion &begin, const Quaternion &end, float cooef);
    void GetAxisAngle(Vector3 &axis, float &angle) const;
    void BuildRotYawPitchRoll(const float yawRadians, const float pitchRadians, const float rollRadians);
    void BuildAxisAngle(const Vector3 &axis, const float radians);

    void Build(const Matrix4x4 &mat);
};

inline Quaternion operator * (const Quaternion &a, const Quaternion &b)
{
    Quaternion* out;
    DirectX::XMStoreFloat4(out,DirectX::XMQuaternionMultiply(DirectX::XMLoadFloat4(&a),DirectX::XMLoadFloat4(&b)));
    return *out;
}

//const Quaternion Quaternion::g_Identity(XMFLOAT4(0,0,0,1));