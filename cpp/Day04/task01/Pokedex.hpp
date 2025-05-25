#ifndef POKEDEX_HPP
#define POKEDEX_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>
#include <fstream>
#include <unordered_set>
#include <functional>

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
    Pokedex(Pokedex&& other) noexcept {
        std::cout << "Move constructor from other" << std::endl;
        *this = std::move(other);
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

    Pokedex& operator=(Pokedex&& other) noexcept {
        if (this != &other) {
            entries = std::move(other.entries);
            other.entries.clear();
        }

        return *this;
    }

    Pokedex& operator+=(const Pokedex& other) {
        std::unordered_set<std::string> existing_names;
        for (const auto& pokemon : entries) {
            existing_names.insert(std::string(pokemon->name()));
        }
        for (const auto& pokemon : other.entries) {
            if (existing_names.find(std::string(pokemon->name())) == existing_names.end()) {
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

    std::ostream& serialise(std::ostream& os) const {
        os << entries.size() << "\n";
        for (const auto& pokemon : entries) {
            os << pokemon->species() << "\n"
               << pokemon->type() << "\n"
               << pokemon->name() << "\n"
               << pokemon->health() << "\n";
        }
        return os;
    }

    std::istream& deserialise(std::istream& is) {
        entries.clear();
        size_t size;
        is >> size;
        is.ignore(); // Ignore the newline after the size
        for (size_t i = 0; i < size; ++i) {
            std::string species, type, name;
            int health;
            std::getline(is, species);
            std::getline(is, type);
            std::getline(is, name);
            is >> health;
            is.ignore();
            entries.push_back(std::make_unique<APokemon>(species, type, name));
        }
        return is;
    }

    template <typename Callable>
    void foreach(Callable&& func) const {
        for (const auto& pokemon : entries) {
            func(*pokemon);
        }
    }
};

std::ostream& operator<<(std::ostream& os, const Pokedex& pokedex) {
    return pokedex.serialise(os);
}

std::istream& operator>>(std::istream& is, Pokedex& pokedex) {
    return pokedex.deserialise(is);
}

}

#endif