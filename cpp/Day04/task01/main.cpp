#include "Nurse.hpp"
#include "Charmander.hpp"
#include "Pikachu.hpp"
#include "APokemon.hpp"
#include "Pokedex.hpp"

void dump_pokemon(const pkmn::IPokemon& pokemon) {
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
    pokedex.foreach(dump_pokemon);
}

int main() {
    pkmn::Pokedex pokedex1;
    pkmn::Pikachu pika1("sbeeve");
    pkmn::Pikachu pika2("pikachu");

    pokedex1.intake(pika1);
    dump_pokedex(pokedex1);

    pkmn::Pokedex pokedex2;
    pokedex2.intake(pika2);
    dump_pokedex(pokedex2);

    pokedex1 += pokedex2;
    dump_pokedex(pokedex1);

    // Serialize the Pokedex to a file
    {
        std::ofstream outpfile("pokedex.txt");
        outpfile << pokedex1;
    }

    // Deserialize the Pokedex from the file
    pkmn::Pokedex deserialized_pokedex;
    {
        std::ifstream istrm("pokedex.txt");
        istrm >> deserialized_pokedex;
    }

    dump_pokedex(deserialized_pokedex);

    return 0;
}