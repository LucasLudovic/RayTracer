//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// DlLib header
//

#pragma once

#include "src/Raytracer/Raytracer.hpp"
#include <memory>
#include <string>

namespace Utils {
    class DlLibError : public std::exception {
       public:
        DlLibError(std::string msg): _msg(msg) {};

        [[nodiscard]] const char *what() const noexcept override
        {
            return this->_msg.c_str();
        };

       private:
        std::string _msg;
    };

    template <class T>
    class DlLib {
       public:
        DlLib(const std::string &shared);
        ~DlLib();

        std::unique_ptr<T> loadLib() const;

       private:
        void *_lib = nullptr;
    };

    template class DlLib<renderer::IRenderer>;

}  // namespace Utils
