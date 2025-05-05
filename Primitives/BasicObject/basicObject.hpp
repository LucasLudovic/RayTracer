//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// basicObject.hpp
//

#pragma once

#include "AObject.hpp"

namespace objects {
    class BasicObject : public objects::AObject {
       public:
        void setType(const std::string &type) { this->_type = type; }
    };

}  // namespace objects
