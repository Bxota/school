#ifndef ASCIICLIP_HPP
#define ASCIICLIP_HPP

#include "AsciiFramebuffer.hpp"

class AsciiClip {
    private:
        AsciiFramebuffer *frameBuffer;
        int size_x;
        int size_y;
        int origin_x;
        int origin_y;

    public:
        AsciiClip(AsciiFramebuffer *asciiFrameBuffer);
        
        void set_origin(int x, int y);
        void set_size(int x, int y);
        void set_pixel(int x, int y, char character);
        char get_pixel(int x, int y);
        void print();
};

#endif // ASCIICLIP_HPP
