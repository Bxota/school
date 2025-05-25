#include "Nurse.hpp"
#include "Charmander.hpp"

void dump_pika(const pkmn::Pikachu &pika) {
    std::cout << pika.species() 
        << " -- of type: " << pika.type() 
        << "-- named: " << pika.name() 
        << "-- hp " << pika.health() << std::endl;

    std::string_view given_name{pika.name()};

    auto numberof_e{std::count(given_name.begin(), given_name.end(), 'e')};
    std::cout << "it's name contains " << numberof_e << " times the letter e " << std::endl;
}

void dump_charm(const pkmn::Charmander &charm) {
    std::cout << charm.species() 
        << " -- of type: " << charm.type() 
        << "-- named: " << charm.name() 
        << "-- hp " << charm.health() << std::endl;

    std::string_view given_name{charm.name()};

    auto numberof_e{std::count(given_name.begin(), given_name.end(), 'e')};
    std::cout << "it's name contains " << numberof_e << " times the letter e " << std::endl;
}

int main() {
    pkmn::Charmander charm("potato");
    dump_charm(charm);
    charm.health() -= 10;
    dump_charm(charm);
}