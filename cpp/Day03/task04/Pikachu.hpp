#ifndef PIKACHU_HPP
#define PIKACHU_HPP

#include "APokemon.hpp"

namespace pkmn {

class Pikachu : public APokemon {
public:
    Pikachu(const std::string& name) : APokemon("Pikachu", "Electric", name) {}
};

} // namespace pkmn

#endif // PIKACHU_HPP