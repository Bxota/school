#include "Pikachu.hpp"

namespace pkmn {

Pikachu::Pikachu(const std::string& name)
    : m_species("Pikachu"), m_type("Electric"), m_name(name), m_health(100) {}

std::string_view Pikachu::species() const {
    return m_species;
}

std::string_view Pikachu::type() const {
    return m_type;
}

std::string_view Pikachu::name() const {
    return m_name;
}

int& Pikachu::health() {
    return m_health;
}

const int& Pikachu::health() const {
    return m_health;
}

bool Pikachu::fainted() const {
    return m_health == 0;
}

} // namespace pkmn