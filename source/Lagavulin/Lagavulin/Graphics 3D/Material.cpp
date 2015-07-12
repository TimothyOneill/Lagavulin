#include "../main/stdafx.h"
#include "Material.h"

Material::Material()
{
    m_Material.Diffuse = g_White;
    m_Material.Ambient = Colour(0.10f, 0.10f, 0.10f, 1.0f);
    m_Material.Specular = g_White;
    m_Material.Emissive = g_Black;
}