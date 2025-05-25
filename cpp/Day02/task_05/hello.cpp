#include "language.hpp"
#include "add_and_print.hpp"
#include "min.hpp"
#include "max.hpp"
#include "pos.hpp"
#include "Assert.hpp"

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
    try {
        stu::assert_eq(5, 5);  // OK
        stu::assert_greater(10, 5);  // OK
        stu::assert_lesser(3, 7);  // OK

        stu::assert_eq(4, 9);  // Va générer une erreur
    } catch (const stu::AssertError& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}