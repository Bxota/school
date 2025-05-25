#include "Nurse.hpp"

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
    pkmn::Pikachu pika("Daniel Croute");

    pika.health() -= 0;

    std::cout << pika.health() << std::endl;
    
    pkmn::Nurse nurse;

    nurse.heal(pika);
    
    std::cout << pika.health() << std::endl;
}