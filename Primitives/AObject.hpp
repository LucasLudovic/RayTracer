//
// EPITECH PROJECT, 2025
// AObject
// File description:
// AObject
//

#include "IObject.hpp"
#include "Utils.hpp"

namespace objects {

    class AObject : public IObject {
       public:
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

       protected:
        Vector3<double> _position;
    };
}  // namespace objects
