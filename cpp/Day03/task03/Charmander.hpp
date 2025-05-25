#ifndef CHARMANDER_HPP
#define CHARMANDER_HPP

#include "IPokemon.hpp"

namespace pkmn {

class Charmander : public IPokemon {
private:
    std::string m_species;
    std::string m_type;
    std::string m_name;
    int m_health;

public:
    Charmander(const std::string& name);

    std::string_view species() const override;
    std::string_view type() const override;
    std::string_view name() const override;

    int& health() override;
    const int& health() const override;

    bool fainted() const override;
};

} // namespace pkmn

#endif // CHARMANDER_HPP