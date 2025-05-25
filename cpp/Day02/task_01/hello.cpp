#include "language.hpp"

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
    hello(Language::SPANISH);
    hello("test");
    hello("test", Language::FRENCH);
}