//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// DlLib header
//

#pragma once

#include "IObject.hpp"
#include "IParser.hpp"
#include "IRenderer.hpp"
#include <memory>
#include <string>

namespace Utils {
    /**
     * @class DlLibError
     * @brief Custom exception for dynamic library loading errors.
     *
     * Inherits from std::exception and holds a specific error message.
     */
    class DlLibError : public std::exception {
       public:
        /**
         * @brief Constructs a DlLibError with the given message.
         * @param msg Error message describing the issue.
         */
        DlLibError(std::string msg) : _msg(msg) {};

        /**
         * @brief Returns the error message.
         * @return A C-style string containing the error message.
         */
        [[nodiscard]] const char *what() const noexcept override
        {
            return this->_msg.c_str();
        };

       private:
        std::string _msg;
    };

    /**
     * @class DlLib
     * @brief Template class for loading symbols from a shared library at runtime.
     *
     * This class loads a dynamic shared object (.so) and extracts a symbol
     * that implements the interface of type T.
     *
     * @tparam T Interface type to be loaded from the library.
     */
    template <class T>
    class DlLib {
       public:
        /**
         * @brief Constructs a DlLib and loads the specified shared library.
         * @param shared Path to the shared library file.
         */
        DlLib(const std::string &shared);
        /**
         * @brief Destructor that unloads the shared library.
         */
        ~DlLib();

        /**
         * @brief Loads a symbol from the shared library.
         * @param symbole Name of the symbol to load.
         * @return A unique pointer to an instance of T.
         */
        std::unique_ptr<T> loadLib(const std::string &symbole) const;

       private:
        void *_lib = nullptr;
    };

    // Explicit template instantiations for known interfaces
    template class DlLib<renderer::IRenderer>;
    template class DlLib<raytracer::IParser>;
    template class DlLib<objects::IObject>;

}  // namespace Utils
