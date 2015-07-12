#pragma once
#include "DirectXPackedVector.h"

/**
Author: Tim O'Neill 07/07/2015
Materials class materials define how and objects surface
interacts with light.
**/

#define fOPAQUE (1.0f)
#define fTRANSPARENT (0.0f)

struct TMaterial
{
    DirectX::PackedVector::XMCOLOR Diffuse;
    DirectX::PackedVector::XMCOLOR Ambient;
    DirectX::PackedVector::XMCOLOR Specular;
    DirectX::PackedVector::XMCOLOR Emissive;
    float Power;
};

typedef DirectX::PackedVector::XMCOLOR Colour;

Colour g_White(1.0f, 1.0f, 1.0f, fOPAQUE);
Colour g_Black(0.0f, 0.0f, 0.0f, fOPAQUE);
Colour g_Cyan(1.0f, 1.0f, 1.0f, fOPAQUE);
Colour g_Red(1.0f, 1.0f, 1.0f, fOPAQUE);
Colour g_Green(1.0f, 1.0f, 1.0f, fOPAQUE);
Colour g_Blue(1.0f, 1.0f, 1.0f, fOPAQUE);
Colour g_Yellow(1.0f, 1.0f, 1.0f, fOPAQUE);
Colour g_Gray40(1.0f, 1.0f, 1.0f, fOPAQUE);
Colour g_Gray25(1.0f, 1.0f, 1.0f, fOPAQUE);
Colour g_Gray65(1.0f, 1.0f, 1.0f, fOPAQUE);
Colour g_Transparent(1.0f, 1.0f, 1.0f, fTRANSPARENT);

class Material
{
    TMaterial m_Material;
public:
    Material();

    void SetAmbient(const Colour &colour)
    {
        m_Material.Ambient = colour;
    }

    void SetDiffuse(const Colour &colour)
    {
        m_Material.Diffuse = colour;
    }

    void SetSpecular(const Colour &colour, const float power)
    {
        m_Material.Specular = colour;
        m_Material.Power = power;
    }

    void SetEmissive(const Colour &colour)
    {
        m_Material.Emissive = colour;
    }

    void SetAlpha(const float alpha)
    {
        m_Material.Diffuse.a = alpha;
    }

    const Colour GetAmbient()
    {
        return m_Material.Ambient;
    }

    const Colour GetDiffuse()
    {
        return m_Material.Diffuse;
    }

    const Colour GetSpecular(Colour &_colour, float &_power)
    {
        _colour = m_Material.Specular;
        _power = m_Material.Power;
    }

    const Colour GetEmissive()
    {
        return m_Material.Emissive;
    }

    bool HasAlpha() const {return GetAlpha() != fOPAQUE; }
    float GetAlpha() const {return m_Material.Diffuse.a; }
};