#include "AsciiClip.hpp"

AsciiClip::AsciiClip(AsciiFramebuffer *asciiFrameBuffer) {
    frameBuffer = asciiFrameBuffer;
}

void AsciiClip::set_origin(int x, int y) {
    origin_x = x;
    origin_y = y;
}

void AsciiClip::set_size(int x, int y) {
    size_x = x;
    size_y = y;
}

void AsciiClip::set_pixel(int x, int y, char character) {
    frameBuffer->set_pixel(origin_x + x, origin_y + y, character);
}

char AsciiClip::get_pixel(int x, int y) {
    return frameBuffer->get_pixel(origin_x + x, origin_y + y);
}

void AsciiClip::print() {
    AsciiFramebuffer tempFramebuffer = AsciiFramebuffer(size_x, size_y);
    
    for (int j = 0; j < size_y; j++) {
        for (int i = 0; i < size_x; i++) {
            tempFramebuffer.set_pixel(i, j, this->get_pixel(i, j));
        }
    }

    tempFramebuffer.print();
}

// int main() {
//     AsciiFramebuffer frame = AsciiFramebuffer(4, 4);

//     for (int j = 0; j < frame.y; j++) {
//         for (int i = 0; i < frame.x; i++) {
//             frame.set_pixel(i, j, '-');
//         }
//     }

//     frame.set_pixel(2, 2, 'o');

//     AsciiClip clip = AsciiClip(&frame);

//     frame.print();
    
//     clip.set_origin(1, 1);
//     clip.set_size(2, 2);

//     clip.print();
// }