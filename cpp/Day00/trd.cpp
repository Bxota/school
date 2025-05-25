#include <iostream>
#include <string>

// int main(int argc, char* argv[]) {
//     if (argc < 2) {
//         std::cerr << argv[0] << ": missing operand" << std::endl;
//         return 1;
//     }

//     std::string chars_to_remove = argv[1];
//     std::string line;

//     while (std::getline(std::cin, line)) {
//         for (char c : chars_to_remove) {
//             line.erase(std::remove(line.begin(), line.end(), c), line.end());
//         }
//         std::cout << line << std::endl;
//     }

//     return 0;
// }