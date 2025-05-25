#include "Nurse.hpp"

namespace pkmn {
    Nurse::Nurse() : m_name("Joy") {}

    void Nurse::heal(IPokemon& pokemon) {        
        if (pokemon.species() == "Pikachu") {
            std::cout << "Oh a Pikachu!" << std::endl;
        } else if (pokemon.species() == "Charmander") {
            std::cout << "Oh a Charmander!" << std::endl;
        }

        if (pokemon.health() <= 50) {
            std::cout << "There there " << pokemon.name() << ", you should feel way better now!" << std::endl;
        } else if (pokemon.health() < 100) {
            std::cout << "That should do it, " << pokemon.name() << "!" << std::endl;
        } else {
            std::cout << "You already are in tip-top shape, " << pokemon.name() << "!" << std::endl;
        }

        pokemon.health() = 100; // Restaure la santé à 100
    }

    std::string_view Nurse::name() {
        return m_name;
    }
}