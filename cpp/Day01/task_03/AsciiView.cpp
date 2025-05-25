#include <iostream>
#include <string_view>

void print(std::string_view sv) {
    std::cout << "StringView: " << sv << " (length: " << sv.size() << ")\n";
}

int main() {
    std::string str = "Hello, world!";
    const char* cstr = "C-string example";
    
    // Création de std::string_view à partir d'un std::string
    std::string_view sv1 = str;
    print(sv1);

    // Création à partir d'un C-string
    std::string_view sv2 = cstr;
    print(sv2);

    // Sous-chaîne avec substr()
    std::string_view sv3 = sv1.substr(7, 5); // "world"
    print(sv3);

    // Accès direct aux caractères
    std::cout << "Premier caractère: " << sv1.front() << "\n";
    std::cout << "Dernier caractère: " << sv1.back() << "\n";

    // Comparaison
    if (sv1 == "Hello, world!") {
        std::cout << "sv1 est égal à 'Hello, world!'\n";
    }

    return 0;
}