#include "Nurse.hpp"

namespace pkmn {
    Nurse::Nurse() : m_name("Joy") {}

    void Nurse::heal(Pikachu &pikachu) {        
        if (pikachu.health() <= 50) {
            std::cout << "There there " << pikachu.name() 
                << ", you should feel way better now!" << std::endl;
        }
        else if (pikachu.health() > 50 && pikachu.health() < 100) {
            std::cout << "That should do it, " << pikachu.name() << " !" << std::endl;
        }
        else {
            std::cout << "You already are in tip-top shape, " << pikachu.name() << " !" << std::endl;
        }

        pikachu.setHealth(100);
    }

    std::string_view Nurse::name() {
        return m_name;
    }
}