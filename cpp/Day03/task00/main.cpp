#include "Pikachu.hpp"

void dump_pika(const pkmn::Pikachu &pika) {
    std::cout << pika.species() 
        << " -- of type: " << pika.type() 
        << "-- named: " << pika.name() 
        << "-- hp " << pika.health() << std::endl;

    std::string_view given_name{pika.name()};

    auto numberof_e{std::count(given_name.begin(), given_name.end(), 'e')};
    std::cout << "it's name contains " << numberof_e << " times the letter e " << std::endl;
}

int main() {
    pkmn::Pikachu pika("sbeeve");

    dump_pika(pika);
    pika.health() -= 10;
    dump_pika(pika);
    pika.health() -= 100;
    dump_pika(pika);
}