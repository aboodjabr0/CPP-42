#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap Default constructor called" << "\n";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "FragTrap Parameterized constructor called" << "\n";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap Copy constructor called" << "\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap Copy assignment operator called" << "\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << "\n";
}

void FragTrap::attack(const std::string& target) {
    if (energyPoints != 0 && hitPoints != 0)
    {
        energyPoints--;
        std::cout << "FragTrap " << this->name << " attacks " << target << " with a frag grenade, dealing " << this->attackDamage << " points of damage!" << "\n";
    }
    else
    {
        std::cout << "FragTrap " << name << " can't attack no energyPoints or hitpoints\n";
    }
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a high five! \\o/" << "\n";
}
