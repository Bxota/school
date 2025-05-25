#ifndef POKEDEX_HPP
#define POKEDEX_HPP

#include <iostream>

#include "IPokemon.hpp"

namespace pkmn {
class Pokedex {
private:
    std::vector<std::unique_ptr<IPokemon>> entries;

public:
    class SearchError : public std::exception {
        private: 
            std::string message;
        public:
            SearchError(const std::string& message) : message(message) {}
            const char* what() const noexcept override {
                return message.c_str();
            }
    };

    Pokedex() {}
    Pokedex(const Pokedex& other) {
        std::cout << "Copy constructor from other" << std::endl;
        *this = other;
    }

    Pokedex& operator=(const Pokedex& other) {
        if (this != &other) {
            entries.clear();
            
            for (const auto& pokemon : other.entries) {
                entries.push_back(pokemon->clone());
            }
        }

        return *this;
    }

    void intake(const IPokemon& pokemon) {
        entries.push_back(pokemon.clone());
    }

    size_t size() const {
        return entries.size();
    }

    const IPokemon& search(const std::string& name) const {
        for (const auto& pokemon : entries) {
            if (pokemon->name() == name) {
                return *pokemon;
            }
        }
        throw SearchError("Pokemon with name '" + name + "' not found.");
    }

    const IPokemon& search(size_t id) const {
        if (id < entries.size()) {
            return *entries[id];
        }
        throw SearchError("Pokemon with id '" + std::to_string(id) + "' not found.");
    }
};
}

#endif