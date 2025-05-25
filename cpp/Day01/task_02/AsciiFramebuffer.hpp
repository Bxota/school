#ifndef ASCIIFRAMEBUFFER_HPP
#define ASCIIFRAMEBUFFER_HPP

#include <tuple>
#include <iostream>

class AsciiFramebuffer {
    private:
        char* array;
    
    public:
        int x;
        int y;

        AsciiFramebuffer(int x, int y);
        
        void set_pixel(int x, int y, char character);
        char get_pixel(int x, int y);
        void print();
        std::tuple<int, int> search(char to_search);
};

#endif // ASCIIFRAMEBUFFER_HPP
