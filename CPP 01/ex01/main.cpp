/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:00:00 by asauafth          #+#    #+#             */
/*   Updated: 2026/03/04 18:05:48 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int hordeSize = 5;
	
	std::cout << "=== Creating a Horde of " << hordeSize << " Zombies ===" << std::endl;
	Zombie* horde = zombieHorde(hordeSize, "Stalkers");
	
	std::cout << "\n=== Each Zombie Announces ===" << std::endl;
	for (int i = 0; i < hordeSize; i++)
	{
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}
	
	std::cout << "\n=== Deleting the Stalkers ===" << std::endl;
	delete[] horde;
    
	return 0;
}
