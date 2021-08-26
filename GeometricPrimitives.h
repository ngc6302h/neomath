#pragma once
#include "Vectors.h"
namespace neo
{
    namespace math
    {
        class Ray
        {
        public:
            Ray() = delete;
            
            Ray(double3 const& origin, double3 const& direction) : m_origin(origin), m_direction(direction) {}
            
            double3 origin() const { return m_origin; }
            double3 direction() const { return m_direction; }
            
            double3 at(double t) const
            {
                return m_origin + m_direction * t;
            }
            
            
            
        private:
            double3 m_origin;
            double3 m_direction;
        };
    }
}
using neo::math::Ray;
