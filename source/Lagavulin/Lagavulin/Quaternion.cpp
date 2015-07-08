#include "stdafx.h"
#include "Quaternion.h"

void Quaternion::Normalize()
{
    DirectX::XMStoreFloat4(this, DirectX::XMQuaternionNormalize(DirectX::XMLoadFloat4(this))); 
}

void Quaternion::Slerp(const Quaternion &begin, const Quaternion &end, float cooef)
{
    //Note: set cooef between 0.0f-1.0f
    DirectX::XMStoreFloat4(this,DirectX::XMQuaternionSlerp(DirectX::XMLoadFloat4(&begin),DirectX::XMLoadFloat4(&end),cooef));
}

void Quaternion::GetAxisAngle(Vector3 &axis, float &angle) const
{
    DirectX::XMQuaternionToAxisAngle(&DirectX::XMLoadFloat3(&axis), &angle, DirectX::XMLoadFloat4(this));
}

void Quaternion::BuildRotYawPitchRoll(const float yawRadians, const float pictchRadians, const float rollRadians)
{
    DirectX::XMStoreFloat4(this, DirectX::XMQuaternionRotationRollPitchYaw(pictchRadians, yawRadians, rollRadians));
}

void Quaternion::BuildAxisAngle(const Vector3 &axis, const float radians)
{
    DirectX::XMStoreFloat4(this, DirectX::XMQuaternionRotationAxis(DirectX::XMLoadFloat3(&axis), radians));
}

void Quaternion::Build(const Matrix4x4 &mat)
{
    DirectX::XMStoreFloat4(this, DirectX::XMQuaternionRotationMatrix(DirectX::XMLoadFloat4x4(&mat)));
}