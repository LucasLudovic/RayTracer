//
// EPITECH PROJECT, 2025
// Utils
// File description:
// Simple class to manipulate objects
//

#pragma once

#include <ostream>
namespace raytracer {

    ///
    /// \class Vector2
    /// \brief 2D mathematical vector class template.
    /// \tparam T The type of the vector components.
    ///
    template <typename T>
    class Vector2 {
       public:
        ///
        /// \brief Default constructor. Initializes both components to zero.
        ///
        Vector2() : _x(0), _y(0) {};

        ///
        /// \brief Constructor with values for both components.
        /// \param x The X component.
        /// \param y The Y component.
        ///
        Vector2(const T &x, const T &y) : _x(x), _y(y) {};

        ///
        /// \brief Default destructor.
        ///
        ~Vector2() = default;

        ///
        /// \brief Sets the X component.
        /// \param value The value to assign to X.
        ///
        void setX(const T &value) noexcept { this->_x = value; };

        ///
        /// \brief Sets the Y component.
        /// \param value The value to assign to Y.
        ///
        void setY(const T &value) noexcept { this->_y = value; };

        ///
        /// \brief Gets the X component.
        /// \return The value of X.
        ///
        [[nodiscard]] T getX() const noexcept { return this->_x; };

        ///
        /// \brief Gets the Y component.
        /// \return The value of Y.
        ///
        [[nodiscard]] T getY() const noexcept { return this->_y; };

        ///
        /// \brief Assignment operator.
        /// \param other Another Vector2 to assign from.
        /// \return Reference to this vector.
        ///
        Vector2<T> &operator=(const Vector2<T> &other)
        {
            if (this != &other) {
                this->_x = other._x;
                this->_y = other._y;
            }
            return *this;
        }

       private:
        T _x; ///< X component.
        T _y; ///< Y component.
    };

    ///
    /// \class Vector3
    /// \brief 3D mathematical vector class template.
    /// \tparam T The type of the vector components.
    ///
    template <typename T>
    class Vector3 {
       public:
        ///
        /// \brief Default constructor. Initializes all components to zero.
        ///
        Vector3() : _x(0), _y(0), _z(0) {};

        ///
        /// \brief Constructor with values for all components.
        /// \param x The X component.
        /// \param y The Y component.
        /// \param z The Z component.
        ///
        Vector3(const T &x, const T &y, const T &z) : _x(x), _y(y), _z(z) {};

        ///
        /// \brief Default destructor.
        ///
        ~Vector3() = default;

        ///
        /// \brief Sets the X component.
        /// \param value The value to assign to X.
        ///
        void setX(const T &value) noexcept { this->_x = value; };

        ///
        /// \brief Sets the Y component.
        /// \param value The value to assign to Y.
        ///
        void setY(const T &value) noexcept { this->_y = value; };

        ///
        /// \brief Sets the Z component.
        /// \param value The value to assign to Z.
        ///
        void setZ(const T &value) noexcept { this->_z = value; };

        ///
        /// \brief Gets the X component.
        /// \return The value of X.
        ///
        [[nodiscard]] T getX() const noexcept { return this->_x; };

        ///
        /// \brief Gets the Y component.
        /// \return The value of Y.
        ///
        [[nodiscard]] T getY() const noexcept { return this->_y; };

        ///
        /// \brief Gets the Z component.
        /// \return The value of Z.
        ///
        [[nodiscard]] T getZ() const noexcept { return this->_z; };

        ///
        /// \brief Assignment operator.
        /// \param other Another Vector3 to assign from.
        /// \return Reference to this vector.
        ///
        Vector3<T> &operator=(const Vector3<T> &other)
        {
            if (this != &other) {
                this->_x = other._x;
                this->_y = other._y;
                this->_z = other._z;
            }
            return *this;
        }

        ///
        /// \brief Subtraction operator for two vectors.
        /// \param other The vector to subtract.
        /// \return The resulting vector.
        ///
        Vector3<T> operator-(const Vector3<T> &other) const
        {
            Vector3<T> newVector;
            newVector._x = this->_x - other._x;
            newVector._y = this->_y - other._y;
            newVector._z = this->_z - other._z;
            return newVector;
        }

        ///
        /// \brief Subtraction operator with a scalar.
        /// \param t The scalar to subtract from each component.
        /// \return The resulting vector.
        ///
        Vector3<T> operator-(const T &t) const
        {
            Vector3<T> newVector;
            newVector._x = this->_x - t;
            newVector._y = this->_y - t;
            newVector._z = this->_z - t;
            return newVector;
        }

        ///
        /// \brief Addition operator for two vectors.
        /// \param other The vector to add.
        /// \return The resulting vector.
        ///
        Vector3<T> operator+(const Vector3<T> &other) const
        {
            Vector3<T> newVector;
            newVector._x = this->_x + other._x;
            newVector._y = this->_y + other._y;
            newVector._z = this->_z + other._z;
            return newVector;
        }

        ///
        /// \brief Multiplication operator for two vectors (component-wise).
        /// \param other The vector to multiply with.
        /// \return The resulting vector.
        ///
        Vector3<T> operator*(const Vector3<T> &other) const
        {
            Vector3<T> newVector;
            newVector._x = this->_x * other._x;
            newVector._y = this->_y * other._y;
            newVector._z = this->_z * other._z;
            return newVector;
        }

        ///
        /// \brief Multiplication operator with a scalar.
        /// \param t The scalar value.
        /// \return The resulting vector.
        ///
        Vector3<T> operator*(const T &t) const
        {
            Vector3<T> newVector;
            newVector._x = this->_x * t;
            newVector._y = this->_y * t;
            newVector._z = this->_z * t;
            return newVector;
        }

        ///
        /// \brief Computes the dot product with another vector.
        /// \param other The vector to compute the dot product with.
        /// \return The dot product value.
        ///
        T dot(const Vector3<T> &other) const noexcept
        {
            return this->_x * other._x + this->_y * other._y +
                   this->_z * other._z;
        }

       private:
        T _x; ///< X component.
        T _y; ///< Y component.
        T _z; ///< Z component.
    };
}  // namespace raytracer

///
/// \brief Output stream operator for Vector3.
/// \param out The output stream.
/// \param vector The Vector3 to output.
/// \return Reference to the stream.
///
template<typename T>
std::ostream &operator<<(std::ostream &out, const raytracer::Vector3<T> &vector)
{
    out << "Vector3: " << vector.getX() << " " << vector.getY() << " " << vector.getZ();
    return out;
}

///
/// \brief Output stream operator for Vector2.
/// \param out The output stream.
/// \param vector The Vector2 to output.
/// \return Reference to the stream.
///
template<typename T>
std::ostream &operator<<(std::ostream &out, const raytracer::Vector2<T> &vector)
{
    out << "Vector2: " << vector.getX() << " " << vector.getY();
    return out;
}
