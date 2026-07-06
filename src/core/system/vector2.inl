#include "Vector2.hpp"

namespace adwg
{
    /**
     * @brief Add two Vector2<T>
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T>
     */
    template <typename T>
    inline Vector2<T> operator +(const Vector2<T> &left, const Vector2<T> &right)
    {
        return Vector2<T>(left.x + right.x, left.y + right.y);
    }

    /**
     * @brief Sub two Vector2<T>
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T>
     */
    template <typename T>
    inline Vector2<T> operator -(const Vector2<T> &left, const Vector2<T> &right)
    {
        return Vector2<T>(left.x - right.x, left.y - right.y);
    }

    /**
     * @brief Add two Vector2<T>
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T>&
     */
    template <typename T>
    inline Vector2<T> &operator +=(Vector2<T> &left, const Vector2<T> &right)
    {
        left.x += right.x;
        left.y += right.y;

        return left;
    }

    /**
     * @brief Sub two Vector2<T>
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T> &
     */
    template <typename T>
    inline Vector2<T>& operator -=(Vector2<T> &left, const Vector2<T> &right)
    {
        left.x -= right.x;
        left.y -= right.y;

        return left;
    }

    /**
     * @brief Multiplie Vector2<T> left by T right
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T>
     */
    template <typename T>
    inline Vector2<T> operator *(const Vector2<T> &left, T right)
    {
        return Vector2<T>(left.x * right, left.y * right);
    }

    /**
     * @brief Multiplie Vector2<T> right by T left
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T>
     */
    template <typename T>
    inline Vector2<T> operator *(T left, const Vector2<T> &right)
    {
        return Vector2<T>(right.x * left, right.y * left);
    }

    /**
     * @brief Div Vector2<T> left by T right
     *
     * @tparam T
     * @param left
     * @param right
     * @return Vector2<T>
     */
    template <typename T>
    inline Vector2<T> operator /(const Vector2<T> &left, T right)
    {
        return Vector2<T>(left.x / right, left.y / right);
    }

    /**
     * @brief Check if two Vector2<T> are equals
     *
     * @tparam T
     * @param left
     * @param right
     * @return true
     * @return false
     */
    template <typename T>
    inline bool operator ==(const Vector2<T> &left, const Vector2<T> &right)
    {
        return ((left.x == right.x) && (left.y == right.y)) ? true : false;
    }

    /**
     * @brief Check if two Vector2<T> are not equals
     *
     * @tparam T
     * @param left
     * @param right
     * @return true
     * @return false
     */
    template <typename T>
    inline bool operator !=(const Vector2<T>& left, const Vector2<T>& right)
    {
        return ((left.x == right.x) && (left.y == right.y)) ? false : true;
    }

    /**
     * @brief Add 1 to Vector2<T> left
     *
     * Usage example :
     * @code
     * vector2f a(1, 2);
     *
     * --a;
     * @endcode
     *
     * @tparam T
     * @param left
     */
    template <typename T>
    inline void operator ++(const Vector2<T>& left)
    {
        ++left.x;
        ++left.y;
    }

    /**
     * @brief Sub 1 to Vector2<T> left
     *
     * Usage example :
     * @code
     * vector2f a(1, 2);
     *
     * --a;
     * @endcode
     *
     * @tparam T
     * @param left
     */
    template <typename T>
    inline void operator --(const Vector2<T>& left)
    {
        left.x--;
        left.y--;
    }
}