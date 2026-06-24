#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    Intern      someRandomIntern;
    Bureaucrat  boss("Boss", 1);
    AForm*      f1 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm*      f2 = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm*      f3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    AForm*      f4 = someRandomIntern.makeForm("unknown form", "target");

    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }
    if (f2)
    {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }
    if (f3)
    {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }
    if (f4)
        delete f4;

    return 0;
}