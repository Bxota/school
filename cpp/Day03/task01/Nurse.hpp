#ifndef NURSE_HPP
#define NURSE_HPP

#include "Pikachu.hpp"

namespace pkmn
{
class Nurse {
private:
    std::string m_name;

public:
    explicit Nurse();
    void heal(Pikachu &pikachu);
    std::string_view name();
};

} // namespace pkmn

#endif