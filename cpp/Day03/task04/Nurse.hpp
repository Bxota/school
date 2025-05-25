#ifndef NURSE_HPP
#define NURSE_HPP

#include <iostream>

#include "IPokemon.hpp"

namespace pkmn
{
class Nurse {
private:
    std::string m_name;

public:
    explicit Nurse();
    void heal(IPokemon &pokemon);
    std::string_view name();
};

} // namespace pkmn

#endif