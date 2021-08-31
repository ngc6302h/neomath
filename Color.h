#pragma once
#include "Vectors.h"

namespace neo
{
    namespace color
    {
        struct rgba;
        
        struct rgb
        {
            rgb() = default;
            
            rgb(unsigned char R, unsigned char G, unsigned char B) : r(R), g(G), b(B)
            {}
            
            rgb(rgba const& other);
            
            static rgb from_float(float R, float G, float B)
            {
                return rgb(R*255.f, G*255.f, B*255.f);
            }
            
            rgb(unsigned char v) : r(v), g(v), b(v)
            {}
            
            rgb(const float3& other) : r(other.x*255.f), g(other.y*255.f), b(other.z*255.f)
            {}
    
            rgb(const double3& other) : r(other.x*255.f), g(other.y*255.f), b(other.z*255.f)
            {}
            
            template<typename ScalarT>
            rgb& operator *=(ScalarT scalar)
            {
                r = ScalarT(r) * scalar;
                g = ScalarT(g) * scalar;
                b = ScalarT(b) * scalar;
                return *this;
            }
            
            rgb& operator +=(rgb const& other)
            {
                r += other.r;
                g += other.g;
                b += other.b;
                return *this;
            }
            
            template<typename ScalarT>
            rgb operator *(ScalarT scalar)
            {
                rgb result(*this);
                result *= scalar;
                return result;
            }
            
            rgb operator +(rgb const& other)
            {
                rgb result(*this);
                result += other;
                return result;
            }
            
            union
            {
                unsigned char data[3];
                struct
                {
                    unsigned char r;
                    unsigned char g;
                    unsigned char b;
                };
            };
        };
        
        template<typename ScalarT>
        rgb operator +(ScalarT left, rgb const& right)
        {
            rgb result(right);
            result += left;
            return result;
        }
        
        template<typename ScalarT>
        rgb operator *(ScalarT left, rgb const& right)
        {
            rgb result(right);
            result *= left;
            return result;
        }
        
        struct rgba
        {
            rgba() = default;
            
            rgba(unsigned char R, unsigned char G, unsigned char B, unsigned char A) : r(R), g(G), b(B), a(A)
            {}
            
            rgba(float R, float G, float B, float A) : r(R*255), g(G*255), b(B*255), a(A*255)
            {}
            
            rgba(unsigned char R, unsigned char G, unsigned char B) : r(R), g(G), b(B), a(255)
            {}
            
            rgba(float R, float G, float B) : r(R*255), g(G*255), b(B*255), a(255)
            {}
            
            rgba(unsigned char v) : r(v), g(v), b(v), a(v)
            {}
            
            rgba(rgb const& color) : r(color.r), g(color.g), b(color.b), a(255)
            {}
            
            template<typename ScalarT>
            rgba& operator *=(ScalarT scalar)
            {
                r = ScalarT(r) * scalar;
                g = ScalarT(g) * scalar;
                b = ScalarT(b) * scalar;
                a = ScalarT(a) * scalar;
                return *this;
            }
            
            rgba& operator +=(rgb const& other)
            {
                r *= other.r;
                g *= other.g;
                b *= other.b;
                return *this;
            }
            
            rgba& operator +=(rgba const& other)
            {
                r += other.r;
                g += other.g;
                b += other.b;
                a += other.a;
                return *this;
            }
            
            template<typename ScalarT>
            rgba operator *(ScalarT scalar)
            {
                rgba result(*this);
                result *= scalar;
                return result;
            }
            
            rgba operator +(rgb const& other)
            {
                rgba result(*this);
                result += other;
                return result;
            }
            
            rgba operator +(rgba const& other)
            {
                rgba result(*this);
                result += other;
                return result;
            }
            
            union
            {
                unsigned char data[4];
                struct
                {
                    unsigned char r;
                    unsigned char g;
                    unsigned char b;
                    unsigned char a {255};
                };
            };
        };
        
        template<typename ScalarT>
        rgba operator +(ScalarT left, rgba const& right)
        {
            rgba result(right);
            result += left;
            return result;
        }
        
        template<typename ScalarT>
        rgba operator *(ScalarT left, rgba const& right)
        {
            rgba result(right);
            result *= left;
            return result;
        }
    
        rgb::rgb(rgba const& other) : r(other.r), g(other.g), b(other.b) {}
    }
}

using neo::color::rgb;
using neo::color::rgba;
