#include <iostream>
#include <tuple>

class AsciiFramebuffer {
    private:
        int x;
        int y;
        char* array;

    public:
        AsciiFramebuffer(int x, int y) {
            this->x = x;
            this->y = y;
            array = new char[x * y]();
        }

        void set_pixel(int x, int y, char character) {
            this->array[(this->x * y) + x] = character;
        }

        char get_pixel(int x, int y) {
            return this->array[(x * this->x) + y];
        }

        void print() {
            char pixel;

            for (int i = 0; i < this->y; ++i) {
                for (int j = 0; j < this->x; ++j) {
                    pixel = (this->array[(i * this->x) + j] != '\0') ? this->array[(i * this->x) + j] : ' ';
                    std::cout << pixel;
                }
                std::cout << std::endl;
            }
        }

        std::tuple<int, int> search(char to_search) {
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
};

int main() {
    AsciiFramebuffer frame = AsciiFramebuffer(10, 10); 

    frame.set_pixel(4, 1, '-');
    //for (int i = 0; i < 10; i++) {
    //}
    frame.print();

    std::tuple<int, int> coordinate = frame.search('-');

    std::cout << std::get<0>(coordinate) << "," << std::get<0>(coordinate) << std::endl;
}