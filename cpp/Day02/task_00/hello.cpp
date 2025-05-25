#include <iostream>

void hello() {
    std::cout << "Hello Stranger!" << std::endl;
}

void hello(std::string str) {
    std::cout << "Hello " << str << "!" << std::endl;
}

int main() {
    hello();
    hello("test");
}