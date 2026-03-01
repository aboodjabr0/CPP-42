#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>

class clsContact
{
private:
    std::string _FirstName;
    std::string _Last_Name;
    std::string _Nickname;
    std::string _PhoneNumber;
    std::string _DarkestSecret;

public:
    void SetFirstName(std::string FirstName);
    void SetLastName(std::string LastName);
    void SetNickname(std::string Nickname);
    void SetPhoneNumber(std::string PhoneNumber);
    void SetDarkestSecret(std::string Secret);

    std::string GetFirstName();
    std::string GetLastName();
    std::string GetNickname();
    std::string GetPhoneNumber();
    std::string GetDarkestSecret();

    void print_info();
};

class clsPhoneBook
{
private:
    clsContact _contacts[8];
    int _ContactCount;
    int _OldestIndex;

    std::string truncate_string(std::string str);

public:
    clsPhoneBook();
    ~clsPhoneBook();

    void Add_Contact();
    void serach_contacts();
    void print_menu();
};

#endif