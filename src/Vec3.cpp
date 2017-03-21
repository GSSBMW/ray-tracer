#include "vec3.hpp"

float Vec3<T>::length()
{
    return sqrt(x * x + y * y + z * z);
}

Vec3<T>& Vec3<T>::normalize()
{
    float len = length();
    if (len > 0)
    {
        float invlen = 1.0 / len;
        x *= invlen;
        y *= invlen;
        z *= invlen;
    }
    
    return *this;
}

T Vec3<T>::dot(const Vec3<T> &v) const
{
    return x * v.x + y * v.y + z * v.z;
}

Vec3<T> Vec3<T>::cross(const Vec3<T> &v) const
{
    return Vec3<T>( y * v.z - z * v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x );
}

Vec3<T> Vec3<T>::operator + (const Vec3<T> &v) const
{
    return Vec3<T>(x + v.x, y + v.y, z + v.z); 
}

Vec3<T> Vec3<T>::operator - (const Vec3<T> &v) const
{
    return Vec3<T>(x - v.x, y - v.y, z - v.z);
}

Vec3<T> Vec3<T>::operator * (const T &r) const
{
    return Vec3<T>(x * r, y * r, z * r);
}
