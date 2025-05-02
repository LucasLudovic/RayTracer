//
// EPITECH PROJECT, 2025
// AObject
// File description:
// AObject
//

#include "IObject.hpp"

namespace objects {

    class AObject : public IObject {
       public:
        AObject() = delete;
        ~AObject() = delete;

        class AObjectError : public IObjectError {
           public:
            AObjectError(const std::string &msg) : _msg(msg) {};
            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            };
           private:
            std::string _msg;
        };
    };
}  // namespace objects
