/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:54:26 by asauafth          #+#    #+#             */
/*   Updated: 2026/03/04 16:54:27 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact _contacts[8];
    int _ContactCount;
    int _OldestIndex;

    std::string truncate_string(std::string str);

public:
    PhoneBook();
    ~PhoneBook();

    void Add_Contact();
    void serach_contacts();
    void print_menu();
};

#endif