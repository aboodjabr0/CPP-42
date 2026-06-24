#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat low("Low", 150);
    Bureaucrat high("High", 1);
    Form       taxForm("TaxForm", 75, 50);

    std::cout << low << std::endl;
    std::cout << high << std::endl;
    std::cout << taxForm << std::endl;

    low.signForm(taxForm);
    std::cout << taxForm << std::endl;

    high.signForm(taxForm);
    std::cout << taxForm << std::endl;

    try
    {
        Form bad("Bad", 0, 151);
        std::cout << bad << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}