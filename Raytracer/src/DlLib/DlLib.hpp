//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// DlLib header
//

#pragma once

#include <memory>
#include <string>

namespace Utils {

    template <typename T>
    class DlLib {
       public:
        DlLib(const std::string &shared);
        ~DlLib();

        class DlLibError : public std::exception {
           public:
            DlLibError(std::string msg);

            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            };

           private:
            std::string _msg;
        };

        std::unique_ptr<T> loadLib() const;

       private:
        void *_lib = nullptr;
    };

}  // namespace Utils
