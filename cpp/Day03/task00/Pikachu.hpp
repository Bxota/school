#ifndef PIKACHU_HPP
#define PIKACHU_HPP

#include <string>
#include <string_view>
#include <iostream>

namespace pkmn {

class Pikachu {
private:
    std::string m_species;
    std::string m_type;
    std::string m_name;
    int m_health;

public:
    explicit Pikachu(const std::string& name);
    std::string_view species() const;
    std::string_view type() const;
    std::string_view name() const;
    int& health();
    const int& health() const;
    bool fainted() const;
};

} // namespace pkmn

#endif // PIKACHU_HPP