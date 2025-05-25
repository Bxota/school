#ifndef CHARMANDER_HPP
#define CHARMANDER_HPP

#include "APokemon.hpp"

namespace pkmn {

class Charmander : public APokemon {
public:
    Charmander(const std::string& name) : APokemon("Charmander", "Fire", name) {}
};

} // namespace pkmn

#endif // CHARMANDER_HPP