/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:54:09 by asauafth          #+#    #+#             */
/*   Updated: 2026/03/04 16:54:10 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>

class Contact
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

#endif