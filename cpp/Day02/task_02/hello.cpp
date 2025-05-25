#include "language.hpp"
#include "add_and_print.hpp"

#include <iostream>

void hello(std::string str = "stranger", Language language = Language::ENGLISH) {
    std::string expression = "";
    
    switch (language)
    {
        case Language::FRENCH:
            expression = "Salut " + str +" !";
            break;
        
        case Language::SPANISH:
            expression = "! Hola " + str + " !";
            break;
        
        case Language::ENGLISH:
        default:
            expression = "Hello " + str + "!";
            break;
    }
    std::cout << expression << std::endl;
}

int main() {
    add_and_print(1, 2);
    add_and_print("salut", "bonjour");
    add_and_print(1, "bonjour");
}