#include "AsciiFramebuffer.hpp"

AsciiFramebuffer::AsciiFramebuffer(int x, int y) {
    this->x = x;
    this->y = y;
    array = new char[x * y]();
}

void AsciiFramebuffer::set_pixel(int x, int y, char character) {
    this->array[(this->x * y) + x] = character;
}

char AsciiFramebuffer::get_pixel(int x, int y) {
    return this->array[(x * this->x) + y];
}

void AsciiFramebuffer::print() {
    char pixel;

    for (int i = 0; i < this->y; ++i) {
        for (int j = 0; j < this->x; ++j) {
            pixel = (this->array[(i * this->x) + j] != '\0') ? this->array[(i * this->x) + j] : ' ';
            std::cout << pixel;
        }
        std::cout << std::endl;
    }
}

std::tuple<int, int> AsciiFramebuffer::search(char to_search) {
    std::tuple<int, int> some_tuple(-1, -1);
    
    for (int i = 0; i < this-> y; i++) {
        for (int j = 0; j < this-> x; j++) {
            if (this->array[i * this->x + j] == to_search) {
                std::get<0>(some_tuple) = j;
                std::get<1>(some_tuple) = i;
                break;
            }
        }
    }

    return some_tuple;
}