#include "phonebook.hpp"


void clsContact::SetFirstName(std::string FirstName)
{
	_FirstName = FirstName;
}

void clsContact::SetLastName(std::string LastName)
{
	_Last_Name = LastName;
}

void clsContact::SetNickname(std::string Nickname)
{
	_Nickname = Nickname;
}

void clsContact::SetPhoneNumber(std::string PhoneNumber)
{
	_PhoneNumber = PhoneNumber;
}

void clsContact::SetDarkestSecret(std::string Secret)
{
	_DarkestSecret = Secret;
}

// Getters
std::string clsContact::GetFirstName()
{
	return _FirstName;
}

std::string clsContact::GetLastName()
{
	return _Last_Name;
}

std::string clsContact::GetNickname()
{
	return _Nickname;
}

std::string clsContact::GetPhoneNumber()
{
	return _PhoneNumber;
}

std::string clsContact::GetDarkestSecret()
{
	return _DarkestSecret;
}

// Methods
void clsContact::print_info()
{
	std::cout << "\nContact Information:\n";
	std::cout << "___________________________________\n";
	std::cout << "FirstName: " << _FirstName << std::endl;
	std::cout << "LastName: " << _Last_Name << std::endl;
	std::cout << "Nickname: " << _Nickname << std::endl;
	std::cout << "PhoneNumber: " << _PhoneNumber << std::endl;
	std::cout << "DarkestSecret: " << _DarkestSecret << std::endl;
}
