#include "Charmander.hpp"

namespace pkmn {

Charmander::Charmander(const std::string& name)
    : m_species("Charmander")
    , m_type("Fire")
    , m_name(name)
    , m_health(100) // default 100 hp
{
}

std::string_view Charmander::species() const {
    return m_species;
}

std::string_view Charmander::type() const {
    return m_type;
}

std::string_view Charmander::name() const {
    return m_name;
}

int& Charmander::health() {
    return m_health;
}

const int& Charmander::health() const {
    return m_health;
}

void Charmander::setHealth(int hp) {
    m_health = (hp < 0) ? 0 : hp;
}

bool Charmander::fainted() const {
    return (std::max(m_health, 0) == 0);
}

} // namespace pkmn