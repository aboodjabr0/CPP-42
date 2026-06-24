#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    Bureaucrat boss("Boss", 1);
    Bureaucrat clerk("Clerk", 140);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm   robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    clerk.signForm(shrub);
    clerk.executeForm(shrub);

    clerk.signForm(robot);
    clerk.executeForm(robot);

    boss.signForm(robot);
    boss.executeForm(robot);

    boss.signForm(pardon);
    boss.executeForm(pardon);

    return 0;
}