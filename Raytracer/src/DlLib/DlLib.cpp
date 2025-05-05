//
// EPITECH PROJECT, 2025
// DlLib
// File description:
// Base function to load a shared library
//

#include "DlLib.hpp"
#include <dlfcn.h>

template<typename T>
Utils::DlLib<T>::DlLib(const std::string &shared)
{
    this->_lib = dlopen(shared.c_str(), RTLD_LAZY);
    if (this->_lib == nullptr)
        throw DlLibError(dlerror());
}

template<typename T>
Utils::DlLib<T>::~DlLib()
{
    if (this->_lib != nullptr) {
        dlclose(this->_lib);
    }
}

template<typename T>
std::unique_ptr<T> Utils::DlLib<T>::loadLib() const
{
    if (this->_lib == nullptr)
        throw DlLibError("Unable to retrieve open lib\n");

    const auto symbol = dlsym(this->_lib, "getObject");
    if (symbol == nullptr)
        throw DlLibError(dlerror());

    auto plugin = reinterpret_cast<std::unique_ptr<T>(*)()>(symbol);
    const auto object = plugin();
    if (object == nullptr)
        throw DlLibError("Can't get object from shared lib\n");
    return object;
}
