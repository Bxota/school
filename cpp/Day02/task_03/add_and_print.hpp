#ifndef ADD_AND_PRINT_HPP
#define ADD_AND_PRINT_HPP

#include <iostream>
#include <string>

// Fonction template pour additionner et afficher le résultat
template <typename T1, typename T2>
auto add_and_print(const T1& a, const T2& b) {
    auto result = std::string(a) + std::string(b);  // Conversion explicite en std::string
    std::cout << result << std::endl;
    return result;
};

// Spécialisation partielle pour les types non chaînes
template <typename T1, typename T2>
requires (!std::is_convertible_v<T1, std::string> || !std::is_convertible_v<T2, std::string>)
auto add_and_print(const T1& a, const T2& b) {
    auto result = a + b;  
    std::cout << result << std::endl;
    return result;
};

#endif // ADD_AND_PRINT_HPP