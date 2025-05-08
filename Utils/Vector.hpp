//
// EPITECH PROJECT, 2025
// Utils
// File description:
// Simple class to manipulate objects
//

#pragma once

namespace raytracer {
    template <typename T>
    class Vector2 {
       public:
        Vector2() : _x(0), _y(0) {};
        Vector2(const T &x, const T &y) : _x(x), _y(y) {};
        ~Vector2() = default;

        void setX(const T &value) noexcept { this->_x = value; };

        void setY(const T &value) noexcept { this->_y = value; };

        [[nodiscard]] T getX() const noexcept { return this->_x; };

        [[nodiscard]] T getY() const noexcept { return this->_y; };

        Vector2<T> &operator=(const Vector2<T> &other)
        {
            if (this != &other) {
                this->_x = other._x;
                this->_y = other._y;
            }
            return *this;
        }

       private:
        T _x;
        T _y;
    };

    template <typename T>
    class Vector3 {
       public:
        Vector3() : _x(0), _y(0), _z(0) {};
        Vector3(const T &x, const T &y, const T &z) : _x(x), _y(y), _z(z) {};
        ~Vector3() = default;

        void setX(const T &value) noexcept { this->_x = value; };

        void setY(const T &value) noexcept { this->_y = value; };

        void setZ(const T &value) noexcept { this->_z = value; };

        [[nodiscard]] T getX() const noexcept { return this->_x; };

        [[nodiscard]] T getY() const noexcept { return this->_y; };

        [[nodiscard]] T getZ() const noexcept { return this->_z; };

        Vector3<T> &operator=(const Vector3<T> &other)
        {
            if (this != &other) {
                this->_x = other._x;
                this->_y = other._y;
                this->_z = other._z;
            }
            return *this;
        }

        Vector3<T> operator-(const Vector3<T> &other)
        {
            Vector3<T> newVector;
            newVector._x = this->_x - other._x;
            newVector._y = this->_y - other._y;
            newVector._z = this->_z - other->_z;
            return newVector;
        }
       private:
        T _x;
        T _y;
        T _z;
    };
}  // namespace raytracer
