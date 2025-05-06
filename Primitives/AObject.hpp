//
// EPITECH PROJECT, 2025
// AObject
// File description:
// AObject
//

#include "../Utils/Vector.hpp"
#include "IObject.hpp"

namespace objects {

    class AObject : public objects::IObject {
       public:
        AObject() : _position(0, 0, 0) {};

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

        std::string getType() const override { return this->_type; };

        void setPosition(raytracer::Vector3<double> pos) override
        {
            this->_position = pos;
        }

        raytracer::Vector3<double> getPosition() override
        {
            return this->_position;
        }

       protected:
        std::string _type;
        raytracer::Vector3<double> _position;
    };
}  // namespace objects
