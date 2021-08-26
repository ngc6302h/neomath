#pragma once
#ifdef __x86_64__
    #include <x86intrin.h>
#endif

namespace neo
{
    namespace math
    {
        namespace detail
        {
            template<typename ScalarT>
            struct  __attribute__ ((packed)) vec3
            {
                vec3() = default;
                
                vec3(ScalarT X, ScalarT Y, ScalarT Z) : x(X), y(Y), z(Z)
                {}
                
                vec3(ScalarT X, ScalarT Y) : x(X), y(Y), z()
                {}
                
                vec3(ScalarT v) : x(v), y(v), z(v)
                {}
                
                vec3& operator +=(vec3 const& other)
                {
                    x += other.x;
                    y += other.y;
                    z += other.z;
                    return *this;
                }
    
                vec3& operator -=(vec3 const& other)
                {
                    x -= other.x;
                    y -= other.y;
                    z -= other.z;
                    return *this;
                }
    
                vec3& operator *=(ScalarT scalar)
                {
                    x *= scalar;
                    y *= scalar;
                    z *= scalar;
                    return *this;
                }
    
                vec3& operator /=(ScalarT scalar)
                {
                    x /= scalar;
                    y /= scalar;
                    z /= scalar;
                    return *this;
                }
    
                vec3 operator +(vec3 const& other) const
                {
                    vec3 result(*this);
                    result += other;
                    return result;
                }
    
                vec3 operator -(vec3 const& other) const
                {
                    vec3 result(*this);
                    result -= other;
                    return result;
                }
                
                vec3 operator *(ScalarT scalar) const
                {
                    vec3 result(*this);
                    result *= scalar;
                    return result;
                }
    
                vec3 operator /(ScalarT scalar) const
                {
                    vec3 result(*this);
                    result /= scalar;
                    return result;
                }
                
                vec3 operator -() const
                {
                    vec3 result {};
                    result -= *this;
                    return result;
                }
                
                ScalarT dot(vec3 const& other) const
                {
                    return x*other.x + y*other.y + z*other.z;
                }
                
                vec3 cross(vec3 const& other) const
                {
                    return vec3(y * other.z - z * other.y, z * other.x - x * other.z , x * other.y - y * other.x);
                }
                
                ScalarT length_sqr() const
                {
                    return x*x + y*y + z*z;
                }
                
                ScalarT length() const
                {
                    if constexpr (sizeof(ScalarT) == 4)
                    {
                        return __builtin_sqrtf(length_sqr());
                    }
                    else
                    {
                        return __builtin_sqrt(length_sqr());
                    }
                }
                
                vec3 normalized() const
                {
                    auto len = length();
                    return vec3(x / len, y / len, z / len);
                }
                
                union
                {
                    ScalarT data[3];
                    struct
                    {
                        ScalarT x;
                        ScalarT y;
                        ScalarT z;
                    };
                };
            };
    
            template<typename ScalarT>
            vec3<ScalarT> operator +(ScalarT left, vec3<ScalarT> const& right)
            {
                vec3<ScalarT> result(right);
                result += left;
                return result;
            }
    
            template<typename ScalarT>
            vec3<ScalarT> operator -(ScalarT left, vec3<ScalarT> const& right)
            {
                vec3<ScalarT> result(right);
                result -= left;
                return result;
            }
    
            template<typename ScalarT>
            vec3<ScalarT> operator *(ScalarT left, vec3<ScalarT> const& right)
            {
                vec3<ScalarT> result(right);
                result *= left;
                return result;
            }
    
            template<typename ScalarT>
            vec3<ScalarT> operator /(ScalarT left, vec3<ScalarT> const& right)
            {
                vec3 result(right);
                result /= left;
                return result;
            }
        }
    }
}

using float3 = neo::math::detail::vec3<float>;
using f32x3 = float3;
using double3 = neo::math::detail::vec3<double>;
using f64x3 = double3;
