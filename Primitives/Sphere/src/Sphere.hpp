//
// EPITECH PROJECT, 2025
// Sphere
// File description:
// Sphere
//

#include "IObject.hpp"

namespace objects {
    class Sphere : public IObject {
       public:
        Sphere();
        ~Sphere();

        class SphereError : public IObjectError {
        };

       private:
    };
}  // namespace objects
