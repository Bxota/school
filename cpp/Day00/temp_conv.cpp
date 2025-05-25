#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

void convert_temperature(std::istream &input, std::ostream &output) {
    double temp;
    char unit;

    // Lire l'entrée depuis l'input stream
    if (!(input >> temp >> unit)) {
        std::cerr << "Error: Invalid input format" << std::endl;
        exit(89);
    }

    double celsius, fahrenheit, kelvin;

    // Conversion selon l'unité fournie
    switch (unit) {
        case 'C':
            celsius = temp;
            fahrenheit = (temp * 9 / 5) + 32;
            kelvin = temp + 273.15;
            break;
        case 'F':
            celsius = (temp - 32) * 5 / 9;
            fahrenheit = temp;
            kelvin = celsius + 273.15;
            break;
        case 'K':
            if (temp < 0) {
                std::cerr << "Error: Invalid temperature in Kelvin" << std::endl;
                exit(89);
            }
            celsius = temp - 273.15;
            fahrenheit = (celsius * 9 / 5) + 32;
            kelvin = temp;
            break;
        default:
            std::cerr << "Error: Unknown unit. Use C, F, or K." << std::endl;
            exit(89);
    }

    // Affichage formaté des températures
    output << std::fixed << std::setprecision(2)
           << celsius << " C\n"
           << fahrenheit << " F\n"
           << kelvin << " K\n";
}

// int main() {
//     while (true) {
//         convert_temperature(std::cin, std::cout);
//     }
//     return 0;
// }
