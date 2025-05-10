//
// EPITECH PROJECT, 2025
// DlLib
// File description:
// Base function to load a shared library
//

#include "DlLib.hpp"
#include <dlfcn.h>
#include <iostream>

template<class T>
Utils::DlLib<T>::DlLib(const std::string &shared)
{
    this->_lib = dlopen(shared.c_str(), RTLD_LAZY);
    if (this->_lib == nullptr)
        throw DlLibError(dlerror());
}

template<class T>
Utils::DlLib<T>::~DlLib()
{
    std::cout << "Je meurs\n";
    if (this->_lib != nullptr)
        dlclose(this->_lib);
}

template<class T>
std::unique_ptr<T> Utils::DlLib<T>::loadLib(const std::string &symName) const
{
    if (this->_lib == nullptr)
        throw DlLibError("Unable to retrieve open lib\n");

    const auto symbol = dlsym(this->_lib, symName.c_str());
    if (symbol == nullptr) {
        throw DlLibError(dlerror());
    }

    auto plugin = reinterpret_cast<std::unique_ptr<T>(*)()>(symbol);
    auto object = plugin();
    if (object == nullptr)
        throw DlLibError("Can't get object from shared lib\n");
    return std::move(object);
}
