#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Bob", 151);
        std::cout << b << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat c("Carol", 149);
        std::cout << c << std::endl;
        c.decrementGrade();
        c.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}