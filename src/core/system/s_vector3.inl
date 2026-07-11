#include "s_vector3.hpp"

namespace adwg {
   
template <typename T>
inline Vector3<T> operator +(const Vector3<T> &left, const Vector3<T> &right)
{
    return Vector3<T>(left.x + right.x, left.y + right.y, left.z + right.z);
}

template <typename T>
inline Vector3<T> operator -(const Vector3<T> &left, const Vector3<T> &right)
{
    return Vector3<T>(left.x - right.x, left.y - right.y, left.z - right.z);
}

template <typename T>
inline Vector3<T> &operator +=(Vector3<T> &left, const Vector3<T> &right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}

template <typename T>
inline Vector3<T>& operator -=(Vector3<T> &left, const Vector3<T> &right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}

template <typename T>
inline Vector3<T> operator *(const Vector3<T> &left, T right)
{
    return Vector3<T>(left.x * right, left.y * right, left.z * right);
}

template <typename T>
inline Vector3<T> operator *(T left, const Vector3<T> &right)
{
    return Vector3<T>(right.x * left, right.y * left, right.z * left);
}

template <typename T>
inline Vector3<T> operator /(const Vector3<T> &left, T right)
{
    return Vector3<T>(left.x / right, left.y / right, left.z / right);
}

template <typename T>
inline bool operator ==(const Vector3<T> &left, const Vector3<T> &right)
{
    return ((left.x == right.x) && (left.y == right.y) && (left.z == right.z)) ? true : false;
}

template <typename T>
inline bool operator !=(const Vector3<T>& left, const Vector3<T>& right)
{
    return ((left.x == right.x) && (left.y == right.y) && (left.z == right.z)) ? false : true;
}

template <typename T>
inline void operator ++(const Vector3<T>& left)
{
    ++left.x;
    ++left.y;
    ++left.z;
}

template <typename T>
inline void operator --(const Vector3<T>& left)
{
    left.x--;
    left.y--;
    left.z--;
}

}