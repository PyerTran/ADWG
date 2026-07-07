#ifndef VECTOR3_HPP_
#define VECTOR3_HPP_

#include <cmath>

namespace adwg {

template <typename T>
class Vector3
{
    public:
        Vector3(const Vector3<T> &vectorSrc) : x(vectorSrc.x), y(vectorSrc.y), z(vectorSrc.z) {}

        Vector3(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}

        T get_distance(const Vector3<T> &vector_endpoint)
        {
            Vector3<T> res = Vector3(vector_endpoint);
            res -= *this;
            T distance = (T)sqrt((res.x**2 + res.y**2 + res.z**2));
            return distance;
        }

        // get the angle between self and endpoint [-180°, 180°]
        double get_angle(const Vector3<T> &vector_endpoint)
        {
            double radian_angle = 0;
            double degree_angle = 0;
            Vector3<T> res = Vector3(vector_endpoint);

            res -= *this;
            radian_angle = atan2(res.y, res.x);
            degree_angle = radian_angle * 180/M_PI;

            return degree_angle;
        }

        T x;
        T y;
        T z;
};

template <typename T>
inline Vector3<T> operator +(const Vector3<T> &left, const Vector3<T> &right);

template <typename T>
inline Vector3<T> operator -(const Vector3<T> &left, const Vector3<T> &right);

template <typename T>
inline Vector3<T> &operator +=(Vector3<T> &left, const Vector3<T> &right);

template <typename T>
inline Vector3<T>& operator -=(Vector3<T> &left, const Vector3<T> &right);

template <typename T>
inline Vector3<T> operator *(const Vector3<T> &left, T right);

template <typename T>
inline Vector3<T> operator *(T left, const Vector3<T> &right);

template <typename T>
inline Vector3<T> operator /(const Vector3<T> &left, T right);

template <typename T>
inline bool operator ==(const Vector3<T> &left, const Vector3<T> &right);

template <typename T>
inline bool operator !=(const Vector3<T>& left, const Vector3<T>& right);

template <typename T>
inline void operator ++(const Vector3<T>& left);

template <typename T>
inline void operator --(const Vector3<T>& left);

}

#endif