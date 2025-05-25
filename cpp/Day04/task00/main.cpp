#include "Nurse.hpp"
#include "Charmander.hpp"
#include "Pikachu.hpp"
#include "APokemon.hpp"
#include "Pokedex.hpp"

void dump_pokemon(const pkmn::APokemon &pokemon) {
    std::cout << pokemon.species() 
        << " -- of type: " << pokemon.type() 
        << "-- named: " << pokemon.name() 
        << "-- hp " << pokemon.health() << std::endl;

    std::string_view given_name{pokemon.name()};

    auto numberof_e{std::count(given_name.begin(), given_name.end(), 'e')};
    std::cout << "it's name contains " << numberof_e << " times the letter e " << std::endl;
}

void dump_pokedex(const pkmn::Pokedex& pokedex) {
    std::cout << "Pokedex size: " << pokedex.size() << std::endl;
}

int main() {
    pkmn::Pokedex pokedex;
    pkmn::Pikachu pika("sbeeve");

    pokedex.intake(pika);
    dump_pokedex(pokedex);

    try {
        const auto& found_pokemon = pokedex.search("sbeeve");
        std::cout << "Found Pokemon: " << found_pokemon.name() << std::endl;
    } catch (const pkmn::Pokedex::SearchError& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        const auto& found_pokemon = pokedex.search(0);
        std::cout << "Found Pokemon: " << found_pokemon.name() << std::endl;
    } catch (const pkmn::Pokedex::SearchError& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        const auto& found_pokemon = pokedex.search("nonexistent");
        std::cout << "Found Pokemon: " << found_pokemon.name() << std::endl;
    } catch (const pkmn::Pokedex::SearchError& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}