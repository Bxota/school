#include "language.hpp"
#include "add_and_print.hpp"
#include "min.hpp"
#include "max.hpp"

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
    std::cout << "Min(3, 7) = " << min(3, 7) << "\n";
    std::cout << "Max(3, 7) = " << max(3, 7) << "\n";

    std::cout << "Min(5.5, 2) = " << min(5.5, 2) << "\n";
    std::cout << "Max(5.5, 2) = " << max(5.5, 2) << "\n";

    std::cout << "Min('a', 'z') = " << min('a', 'z') << "\n";
    std::cout << "Max('a', 'z') = " << max('a', 'z') << "\n";

    return 0;
}