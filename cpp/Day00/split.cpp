#include <iostream>
#include <string>

std::vector<std::string> split(std::string to_parse, std::string token) {
    std::vector<std::string> result;
    size_t pos = 0;

    while ((pos = to_parse.find(token)) != std::string::npos) {
        std::string to_add = to_parse.substr(0, pos);
        if (to_add.length() > 0) {
            result.push_back(to_add);
        }
        
        to_parse.erase(0, pos + token.length());
    }

    result.push_back(to_parse);
    
    return result;
}

std::vector<std::string> split(std::string to_parse, char token) {
    std::vector<std::string> result;
    size_t start = 0, pos;

    while ((pos = to_parse.find(token, start)) != std::string::npos) {
        std::string to_add = to_parse.substr(start, pos - start);
        if (to_add.length() > 0) {
            result.push_back(to_add);
        }
        start = pos + 1;
    }
    result.push_back(to_parse.substr(start));

    return result;
}

int main(void) {
    auto cb{[](std::string &s) { std::cout << s << std::endl; }};
    {
        auto result{split("electric;dragon",';')};
        std::for_each(result.begin(), result.end(), cb);
    }
    {
        auto result{split(";fire;;;flying",";")};
        std::for_each(result.begin(), result.end(), cb);
    }
    {
        auto result{split("grass-->poison","-->")};
        std::for_each(result.begin(), result.end(), cb);
    }
}