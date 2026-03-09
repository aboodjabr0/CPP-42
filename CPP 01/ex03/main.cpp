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

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon club("AWP");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("AK-47");
		bob.attack();
	}
	{
		Weapon club("Vandal");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("Sherif");
		jim.attack();
	}
	return 0;
}
