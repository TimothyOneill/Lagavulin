#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include "DirectXMath.h"

/**
Author: Tim O'Neill 07/07/2015
Implementation of a 4x4 matrix wrapper around DirectX
**/

class Matrix4x4 : public DirectX::XMFLOAT4X4
{
public:
    friend class Quaternion;
    static const Matrix4x4 g_Identity;

    Matrix4x4() : XMFLOAT4X4() {};
    Matrix4x4(XMFLOAT4X4 &mat) { memcpy(&m, &mat.m, sizeof(mat.m)); }

    //Modifiers
    inline void SetPosition(Vector3 const &pos)
    {
        m[3][0] = pos.x;
        m[3][1] = pos.y;
        m[3][2] = pos.z;
        m[3][3] = 1.0f;
    }

    inline void SetPosition(Vector4 const &pos)
    {
        m[3][0] = pos.x;
        m[3][1] = pos.y;
        m[3][2] = pos.z;
        m[3][3] = pos.w;
    }

    //Accessors and Calculations
    inline Vector3 GetPosition() const
    {
        return Vector3(m[3][0], m[3][1], m[3][2]);
    }

    inline Vector3 Xform(Vector3 &v) const
    {
        Vector3* Out;
        DirectX::XMStoreFloat3(Out, DirectX::XMVector4Transform(DirectX::XMLoadFloat3(&v),DirectX::XMLoadFloat4x4(this)));
        return *Out;
    }

    inline Vector4 Xform(Vector4 &v) const
    {
        Vector4* Out;
        DirectX::XMStoreFloat4(Out, DirectX::XMVector4Transform(DirectX::XMLoadFloat4(&v),DirectX::XMLoadFloat4x4(this)));
        return *Out;
    }

    inline Matrix4x4 Inverse() const
    {
       Matrix4x4* Out;
       DirectX::XMStoreFloat4x4(Out, DirectX::XMMatrixInverse(NULL,DirectX::XMLoadFloat4x4(this)));
       return *Out;
    }

    //Intializtion Methods
    inline void BuildTranslation(const Vector3 &pos)
    {
        *this = Matrix4x4::g_Identity;
        m[3][0] = pos.x;
        m[3][1] = pos.y;
        m[3][2] = pos.z;
    }

    inline void BuildTranslation(const float x, const float y, const float z)
    {
        *this = Matrix4x4::g_Identity;
        m[3][0] = x;
        m[3][1] = y;
        m[3][2] = z;
    }

    inline void BuildRotationX(const float radians)
    {
        DirectX::XMStoreFloat4x4(this, DirectX::XMMatrixRotationX(radians));
    }

    inline void BuildRotationY(const float radians)
    {
        DirectX::XMStoreFloat4x4(this, DirectX::XMMatrixRotationY(radians));
    }

    inline void BuildRotationZ(const float radians)
    {
        DirectX::XMStoreFloat4x4(this, DirectX::XMMatrixRotationZ(radians));
    }

    inline void BuildYawPitchRoll(const float yawRadians, const float pitchRadians, const float rollRadians)
    {
        DirectX::XMStoreFloat4x4(this, DirectX::XMMatrixRotationRollPitchYaw(pitchRadians, yawRadians, rollRadians));
    }

    //TODOShould the quaternion or matrix have ownership of building the rotation matrix
    /*
    inline void BuildRotationQuaternion(const Quaternion &q)
    {
        DirectX::XMStoreFloat4x4(this, DirectX::XMMatrixRotationQuaternion(DirectX::XMLoadFloat4(&q)));
    }
    */
    inline void BuildRotationLookAt(const Vector3 &eye, const Vector3 &at, const Vector3 &up)
    {
        DirectX::XMStoreFloat4x4(this, DirectX::XMMatrixLookAtRH(DirectX::XMLoadFloat3(&eye),DirectX::XMLoadFloat3(&at),DirectX::XMLoadFloat3(&up)));
    }
};

inline Matrix4x4 operator * (const Matrix4x4 &a, const Matrix4x4 &b)
{
    Matrix4x4* Out;
    DirectX::XMStoreFloat4x4(Out,DirectX::XMMatrixMultiply(DirectX::XMLoadFloat4x4(&a),DirectX::XMLoadFloat4x4(&b)));
    return *Out;
}

//const Matrix4x4 Matrix4x4::g_Identity(DirectX::XMFLOAT4X4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1));