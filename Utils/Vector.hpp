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
        Vector2() = delete;
        Vector2(const T &x, const T &y) : _x(x), _y(y) {};
        ~Vector2() = default;

        void setX(const T &value) { this->_x = value; };

        void setY(const T &value) { this->_y = value; };

        [[nodiscard]] T getX() { return this->_x; };

        [[nodiscard]] T getY() { return this->_y; };

       private:
        T _x;
        T _y;
    };

    template <typename T>
    class Vector3 {
       public:
        Vector3() = delete;
        Vector3(const T &x, const T &y, const T &z) : _x(x), _y(y), _z(z) {};
        ~Vector3() = default;

        void setX(const T &value) { this->_x = value; };

        void setY(const T &value) { this->_y = value; };

        void setZ(const T &value) { this->_z = value; };

        [[nodiscard]] T getX() { return this->_x; };

        [[nodiscard]] T getY() { return this->_y; };

        [[nodiscard]] T getZ() { return this->_z; };

        Vector3<T> &operator=(const Vector3<T> &other)
        {
            if (this != &other) {
                this->_x = other._x;
                this->_y = other._y;
                this->_z = other._z;
            }
            return *this;
        }

       private:
        T _x;
        T _y;
        T _z;
    };
}  // namespace raytracer
