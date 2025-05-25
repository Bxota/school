#include "language.hpp"
#include "add_and_print.hpp"
#include "min.hpp"
#include "max.hpp"
#include "pos.hpp"

#include <iostream>

void hello(const std::string& name, Language lang = Language::ENGLISH) {
    switch (lang) {
        case Language::FRENCH:
            std::cout << "Bonjour " << name << "!" << std::endl;
            break;
        case Language::SPANISH:
            std::cout << "Hola " << name << "!" << std::endl;
            break;
        case Language::ENGLISH:
        default:
            std::cout << "Hello " << name << "!" << std::endl;
            break;
    }
}

void hello(Language lang) {
    hello("stranger", lang);
}

int main() {
    pos_2d<int> position;
    position.x = 12;
    position.y = 89;

    pos_3d<float> angles;
    angles.x = 0.145;
    angles.y = 1.57;
    angles.z = 3.14;

    std::cout << "Position 2D: (" << position.x << ", " << position.y << ")\n";
    std::cout << "Position 3D: (" << angles.x << ", " << angles.y << ", " << angles.z << ")\n";

    return 0;
}