#ifndef PIKACHU_HPP
#define PIKACHU_HPP

#include "IPokemon.hpp"

namespace pkmn {

class Pikachu : public IPokemon {
private:
    std::string m_species;
    std::string m_type;
    std::string m_name;
    int m_health;

public:
    Pikachu(const std::string& name);

    std::string_view species() const override;
    std::string_view type() const override;
    std::string_view name() const override;

    int& health() override;
    const int& health() const override;

    bool fainted() const override;
};

} // namespace pkmn

#endif // PIKACHU_HPP