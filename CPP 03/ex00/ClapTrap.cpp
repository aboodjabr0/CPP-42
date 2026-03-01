#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap Default constructor called" << "\n";
    name = "unnamed";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name) {
    std::cout << "ClapTrap Parameterized constructor called" << "\n";
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap Copy constructor called" << "\n";
    this->name = other.name;
    this->attackDamage = other.attackDamage;
    this->energyPoints = other.energyPoints;
    this->hitPoints = other.hitPoints;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap Copy assignment operator called" << "\n";
    if (this != &other)
    {
        this->name = other.name;
        this->attackDamage = other.attackDamage;
        this->energyPoints = other.energyPoints;
        this->hitPoints = other.hitPoints;
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called" << "\n";
}

void ClapTrap::attack(const std::string& target) {
    if (energyPoints != 0 && hitPoints != 0)
    {
        energyPoints--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << "\n";
    }
    else
    {
        std::cout << "ClapTrap " << name << " can't attack no energyPoints or hitpoints\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints != 0)
    {
        if (amount >= hitPoints)
            hitPoints = 0;
        else
            hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage! Current hit points: " << this->hitPoints << "\n";
    }
    else
    {
        std::cout << "ClapTrap " << name << " can't take damage hitpoints is 0\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints != 0)
    {
        energyPoints--;
        hitPoints += amount;
        std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points! Current hit points: " << this->hitPoints << "\n";
    }
    else
    {
        std::cout << "ClapTrap " << name << " can't beRepaired no energyPoints\n";
    }
}
