#ifndef IPOKEMON_HPP
#define IPOKEMON_HPP

#include <string>
#include <string_view>

namespace pkmn {

class IPokemon {
public:
    virtual ~IPokemon() = default;
    virtual std::string_view species() const = 0;
    virtual std::string_view type() const = 0;
    virtual std::string_view name() const = 0;
    virtual int& health() = 0;
    virtual const int& health() const = 0;
    virtual bool fainted() const = 0;
    virtual std::unique_ptr<IPokemon> clone() const = 0;
};

} // namespace pkmn

#endif // IPOKEMON_HPP