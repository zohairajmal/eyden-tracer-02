#pragma once

#include "ShaderFlat.h"

/**
 * @brief Eye-light shader class
 */
class CShaderEyelight : public CShaderFlat
{
public:
    /**
     * @brief Constructor
     * @details This is a texture-free and light-source-free shader
     * @param scene Reference to the scene
     * @param color The color of the object
     */
    CShaderEyelight(Vec3f color = RGB(0.5f, 0.5f, 0.5f))
        : CShaderFlat(color)
    {
    }
    virtual ~CShaderEyelight(void) = default;

    virtual Vec3f Shade(const Ray &ray) const override
    {
        // result = |cos(theta)| color. Theta is the angle between surface normal and the ray
        // normal.dot(-dir) = cos(theta) * 1 * 1 = cos(theta) (since the lengths for dir and normal are 1)
        float cosTheta = (ray.hit->GetNormal(ray)).dot(-ray.dir);
        return (fabs(cosTheta) * CShaderFlat::Shade(ray));
    }
};
