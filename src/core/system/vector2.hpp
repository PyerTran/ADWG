#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

namespace adwg
{
    /**
     * @class acd::Vector2<T>
     *
     * @brief Utility class for manipulating 2 dimensional vector
     *
     * The operators {+, -, +=, -=, ++, --, *, /, ==} are available in
     * the Vector2.inl file.
     * This can help you easily manipulate different Vector2 classes.
     *
     * @param T
     *
     * @ingroup System
     */
    template <typename T>
    class Vector2
    {
        public:
            /**
              * @brief Default constructor, creates a Vector2(vectSrc.x, vectSrc.y)
              *
              * @tparam T
              * @param vectSrc
              */
            Vector2(const Vector2<T> &vectorSrc) : x(vectorSrc.x), y(vectorSrc.y) {}

            /**
              * @brief Default constructor, creates a Vector2(0, 0)
              *
              * @param x x coordinate
              * @param y y coordinate
              */
            Vector2(T x=0, T y=0) : x(x), y(y) {}

            T x;
            T y;
    }; // class Vector2

    typedef Vector2<int>    Vector2i;
    typedef Vector2<float>  Vector2f;

    /**
     * @brief Add two Vector2<T>
     *
     * Usage example :
     * @code
     * Vector2i a(1, 2);
     * Vector2i b(4, 1);
     *
     * a = a + b;
     * @endcode
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T>
     */
    template <typename T>
    inline Vector2<T> operator +(const Vector2<T> &left, const Vector2<T> &right);

    /**
     * @brief Sub two Vector2<T>
     *
     * Usage example :
     * @code
     * Vector2i a(1, 2);
     * Vector2i b(4, 1);
     *
     * a = a - b;
     * @endcode
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T>
     */
    template <typename T>
    inline Vector2<T> operator -(const Vector2<T> &left, const Vector2<T> &right);

    /**
     * @brief Add two Vector2<T>
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T>&
     */
    template <typename T>
    inline Vector2<T> &operator +=(Vector2<T> &left, const Vector2<T> &right);

    /**
     * @brief Sub two Vector2<T>
     *
     * Usage example :
     * @code
     * Vector2i a(1, 2);
     * Vector2i b(4, 1);
     *
     * a += b;
     * @endcode
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T> &
     */
    template <typename T>
    inline Vector2<T>& operator -=(Vector2<T> &left, const Vector2<T> &right);

    /**
     * @brief Multiplie Vector2<T> left by T right
     *
     * Usage example :
     * @code
     * Vector2i a(1, 2);
     * Vector2i b(4, 1);
     *
     * a -= b;
     * @endcode
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T>
     */
    template <typename T>
    inline Vector2<T> operator *(const Vector2<T> &left, T right);

    /**
     * @brief Multiplie Vector2<T> right by T left
     *
     * Usage example :
     * @code
     * Vector2i a(1, 2);
     *
     * a = 3 * a
     * @endcode
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T>
     */
    template <typename T>
    inline Vector2<T> operator *(T left, const Vector2<T> &right);

    /**
     * @brief Div Vector2<T> left by T right
     *
     * Usage example :
     * @code
     * Vector2i a(1, 2);
     *
     * a = a / 3
     * @endcode
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T>
     */
    template <typename T>
    inline Vector2<T> operator /(const Vector2<T> &left, T right);

    /**
     * @brief Check if two Vector2<T> are equals
     *
     *Usage example :
     * @code
     * Vector2i a(1, 2);
     * Vector2i b(3, 1);
     *
     * if (a == b)
     *    b++;
     * @endcode
     *
     * @tparam T
     * @param left
     * @param right
     * @return true
     * @return false
     */
    template <typename T>
    inline bool operator ==(const Vector2<T> &left, const Vector2<T> &right);

    /**
     * @brief Check if two Vector2<T> are not equals
     *
     * Usage example :
     * @code
     * Vector2i a(1, 2);
     * Vector2i b(3, 1);
     *
     * if (a != b)
     *    a++;
     * @endcode
     *
     * @tparam T
     * @param left
     * @param right
     * @return true
     * @return false
     */
    template <typename T>
    inline bool operator !=(const Vector2<T>& left, const Vector2<T>& right);

    /**
     * @brief Add 1 to Vector2<T> left
     *
     * Usage example :
     * @code
     * Vector2i a(1, 2);
     *
     * --a;
     * @endcode
     *
     * @tparam T
     * @param left
     */
    template <typename T>
    inline void operator ++(const Vector2<T>& left);

    /**
     * @brief Sub 1 to Vector2<T> left
     *
     * Usage example :
     * @code
     * Vector2i a(1, 2);
     *
     * --a;
     * @endcode
     *
     * @tparam T
     * @param left
     */
    template <typename T>
    inline void operator --(const Vector2<T>& left);
}

#include "vector2.inl"

#endif