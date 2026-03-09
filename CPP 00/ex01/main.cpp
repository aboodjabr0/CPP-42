/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:00:00 by asauafth          #+#    #+#             */
/*   Updated: 2026/03/04 00:00:00 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;

	phonebook.print_menu();
	while (true)
	{
		std::cout << "\nEnter command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "\nGoodbye! All contacts will be lost forever...\n";
			break;
		}
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
