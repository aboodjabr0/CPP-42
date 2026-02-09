#include "phonebook.hpp"

clsPhoneBook::clsPhoneBook()
{
	_ContactCount = 0;
	_OldestIndex = 0;
}

clsPhoneBook::~clsPhoneBook()
{
}

std::string clsPhoneBook::truncate_string(std::string str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str += ".";
	}
	return (str);
}

void clsPhoneBook::Add_Contact()
{
	std::string input;

	std::cout << "\n=== Adding New Contact ===\n";

	std::cout << "Enter First Name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: First Name cannot be empty.";
		return;
	}
	_contacts[_OldestIndex].SetFirstName(input);

	std::cout << "Enter Last Name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: Last Name cannot be empty.";
		return;
	}
	_contacts[_OldestIndex].SetLastName(input);

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: Nickname cannot be empty.";
		return;
	}
	_contacts[_OldestIndex].SetNickname(input);

	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: Phone Number cannot be empty.";
		return;
	}
	_contacts[_OldestIndex].SetPhoneNumber(input);

	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: Darkest Secret cannot be empty.";
		return;
	}
	_contacts[_OldestIndex].SetDarkestSecret(input);

	std::cout << "Contact added successfully!\n";
	_OldestIndex = (_OldestIndex + 1) % 8;
	if (_ContactCount < 8)
		_ContactCount++;
}

void clsPhoneBook::serach_contacts()
{
	if (_ContactCount == 0)
	{
		std::cout << "Phonebook is empty. No contacts to display.\n";
		return;
	}

	std::cout << "\n=== Contact List ===\n";
	std::cout << std::setw(10) << "Index" << "|"
		 << std::setw(10) << "First Name" << "|"
		 << std::setw(10) << "Last Name" << "|"
		 << std::setw(10) << "Nickname" << "\n";
	std::cout << "-------------------------------------------\n";

	for (int i = 0; i < _ContactCount; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|"
			 << std::setw(10) << truncate_string(_contacts[i].GetFirstName()) << "|"
			 << std::setw(10) << truncate_string(_contacts[i].GetLastName()) << "|"
			 << std::setw(10) << truncate_string(_contacts[i].GetNickname()) << "\n";
	}

	std::cout << "Enter the index of the contact to view details: ";
	std::string input;
	std::getline(std::cin, input);
	
	int index = 0;
	bool valid = true;
	
	if (input.empty())
		valid = false;
	
	for (size_t i = 0; i < input.length() && valid; i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
			index = index * 10 + (input[i] - '0');
		else
			valid = false;
	}

	if (!valid || index < 1 || index > _ContactCount)
	{
		std::cout << "Error: Invalid index.\n";
		return;
	}

	_contacts[index - 1].print_info();
}

void clsPhoneBook::print_menu()
{
	std::cout << "\n=================================\n";
	std::cout << "     AWESOME PHONEBOOK 80s\n";
	std::cout << "=================================\n";
	std::cout << "Commands:\n";
	std::cout << "  ADD    - Add a new contact\n";
	std::cout << "  SEARCH - Search and display contacts\n";
	std::cout << "  EXIT   - Exit the program\n";
	std::cout << "=================================\n";
}
