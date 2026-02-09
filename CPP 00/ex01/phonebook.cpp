#include "phonebook.hpp"

int main()
{
	clsPhoneBook phonebook;
	std::string command;

	phonebook.print_menu();
	while (true)
	{
		std::cout << "\nEnter command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			phonebook.Add_Contact();
		}
		else if (command == "SEARCH")
		{
			phonebook.serach_contacts();
		}
		else if (command == "EXIT")
		{
			std::cout << "\nGoodbye! All contacts will be lost forever...\n";
			break;
		}
		else
		{
			if (!command.empty())
				std::cout << "Invalid command! Use ADD, SEARCH, or EXIT.\n";
		}
	}
	return (0);
}
