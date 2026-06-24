#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed for " << _target << "." << std::endl;
}