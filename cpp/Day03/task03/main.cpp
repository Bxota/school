#include "Nurse.hpp"
#include "Charmander.hpp"
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
    pkmn::Pikachu pika("Sparky");
    pika.health() -= 30;
    
    pkmn::Charmander charmy("Blaze");
    charmy.health() -= 70;

    pkmn::Nurse nurse;

    nurse.heal(pika);  
    nurse.heal(charmy);

    return 0;
}