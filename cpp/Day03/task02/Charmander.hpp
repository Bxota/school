#ifndef CHARMANDER_HPP
#define CHARMANDER_HPP

#include <string>
#include <string_view>
#include <iostream>

namespace pkmn {

class Charmander {
private:
    std::string m_species;
    std::string m_type;
    std::string m_name;
    int m_health;

public:
    explicit Charmander(const std::string& name);
    std::string_view species() const;
    std::string_view type() const;
    std::string_view name() const;
    int& health();
    const int& health() const;
    void setHealth(int hp);
    bool fainted() const;
};

} // namespace pkmn

#endif // CHARMANDER_HPP