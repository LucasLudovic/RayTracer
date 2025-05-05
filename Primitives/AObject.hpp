//
// EPITECH PROJECT, 2025
// AObject
// File description:
// AObject
//

#include "IObject.hpp"
#include "Vector.hpp"

namespace objects {

    class AObject : public IObject {
       public:
        AObject(): _position(0, 0, 0) {};
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
        raytracer::Vector3<double> _position;
    };
}  // namespace objects
