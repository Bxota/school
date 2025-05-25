#include <iostream>
#include <string>

// int main(int argc, char* argv[]) {
//     if (argc < 2) {
//         std::cerr << argv[0] << ": missing operand" << std::endl;
//         return 1;
//     }

//     std::string chars_to_process = argv[1];
//     std::string line;

//     while (std::getline(std::cin, line)) {
//         std::string filtered;
//         for (char c : line) {
//             if (chars_to_process.find(c) != std::string::npos) {
//                 filtered += c;
//             }
//         }
//         line = filtered;

//         std::cout << line << std::endl;
//     }

//     return 0;
// }