/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:53:57 by asauafth          #+#    #+#             */
/*   Updated: 2026/03/04 16:53:58 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::SetFirstName(std::string FirstName)
{
	_FirstName = FirstName;
}

void Contact::SetLastName(std::string LastName)
{
	_Last_Name = LastName;
}

void Contact::SetNickname(std::string Nickname)
{
	_Nickname = Nickname;
}

void Contact::SetPhoneNumber(std::string PhoneNumber)
{
	_PhoneNumber = PhoneNumber;
}

void Contact::SetDarkestSecret(std::string Secret)
{
	_DarkestSecret = Secret;
}

std::string Contact::GetFirstName()
{
	return _FirstName;
}

std::string Contact::GetLastName()
{
	return _Last_Name;
}

std::string Contact::GetNickname()
{
	return _Nickname;
}

std::string Contact::GetPhoneNumber()
{
	return _PhoneNumber;
}

std::string Contact::GetDarkestSecret()
{
	return _DarkestSecret;
}

void Contact::print_info()
{
	std::cout << "\nContact Information:\n";
	std::cout << "___________________________________\n";
	std::cout << "FirstName: " << _FirstName << std::endl;
	std::cout << "LastName: " << _Last_Name << std::endl;
	std::cout << "Nickname: " << _Nickname << std::endl;
	std::cout << "PhoneNumber: " << _PhoneNumber << std::endl;
	std::cout << "DarkestSecret: " << _DarkestSecret << std::endl;
}
