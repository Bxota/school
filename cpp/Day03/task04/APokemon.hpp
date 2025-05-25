#ifndef APOKEMON_HPP
#define APOKEMON_HPP

#include "IPokemon.hpp"
#include <string>

namespace pkmn {

class APokemon : public IPokemon {
protected:
    std::string m_species;
    std::string m_type;
    std::string m_name;
    int m_health;

public:
    APokemon(const std::string& species, const std::string& type, const std::string& name)
        : m_species(species), m_type(type), m_name(name), m_health(100) {}

    std::string_view species() const override {
        return m_species;
    }

    std::string_view type() const override {
        return m_type;
    }

    std::string_view name() const override {
        return m_name;
    }

    int& health() override {
        return m_health;
    }

    const int& health() const override {
        return m_health;
    }

    bool fainted() const override {
        return m_health == 0;
    }
};

} // namespace pkmn

#endif // APOKEMON_HPP