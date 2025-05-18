//
// EPITECH PROJECT, 2025
// Base
// File description:
// Base functions
//

#include "IObject.hpp"
#include "Sphere.hpp"

/// @brief Constructeur par défaut de la classe Sphere.
/// Initialise une instance de Sphere dérivée de AObject.
objects::Sphere::Sphere() : AObject()
{
}

/// @brief Clone l'objet Sphere actuel.
/// @return Un pointeur unique vers une copie de l'objet Sphere.
std::unique_ptr<objects::IObject> objects::Sphere::clone() const {
    return std::make_unique<objects::Sphere>(*this);
}

extern "C" {

/// @brief Fonction d'usine pour créer une instance de Sphere.
/// @return Un pointeur unique vers une nouvelle instance de Sphere.
std::unique_ptr<objects::IObject> objects::createPrimitive(void)
{
    return std::make_unique<objects::Sphere>();
}
}
