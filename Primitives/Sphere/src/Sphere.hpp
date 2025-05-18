//
// EPITECH PROJECT, 2025
// Sphere
// File description:
// Sphere
//

#pragma once

#include "AObject.hpp"

namespace objects {

    /// @class Sphere
    /// @brief Représente une sphère géométrique dans un moteur de raytracing.
    ///
    /// Cette classe dérivée de AObject fournit une implémentation spécifique
    /// pour tester les collisions entre un rayon et une sphère. Elle supporte
    /// également la duplication via la méthode clone.
    class Sphere : public AObject {
       public:
        /// @brief Constructeur par défaut.
        ///
        /// Initialise une sphère avec des paramètres par défaut.
        Sphere();

        /// @brief Clone l'objet courant.
        ///
        /// @return Un pointeur unique vers une nouvelle instance de Sphere identique.
        std::unique_ptr<IObject> clone() const override;

        /// @brief Retourne le type de l'objet.
        ///
        /// @return Une chaîne de caractères représentant le type : "Sphere".
        std::string getType() const override { return "Sphere"; }

        /// @brief Détermine si un rayon frappe la sphère.
        ///
        /// @param ray Le rayon à tester.
        /// @param result Structure contenant les informations du point d'impact si intersection.
        /// @return true si le rayon touche la sphère, false sinon.
        bool hit(const raytracer::Raycast &ray, objects::hitResult_t &result) const override;

       private:
        double _radius; ///< Rayon de la sphère.
    };

}  // namespace objects
