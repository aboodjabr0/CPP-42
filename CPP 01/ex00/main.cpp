/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:01:08 by asauafth          #+#    #+#             */
/*   Updated: 2026/03/04 18:03:49 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << "=== Creating Zombie on the HEAP ===" << std::endl;
	Zombie* heapZombie = newZombie("the walking dead");
	heapZombie->announce();
	
	std::cout << "\n=== Creating Zombie on the STACK ===" << std::endl;
	randomChump("qlicker");
	
	std::cout << "\n=== Creating another Stack Zombie ===" << std::endl;
	randomChump("walker");
	
	std::cout << "\n=== Manual deletion of Heap Zombie ===" << std::endl;
	delete heapZombie;
	
	std::cout << "\n=== Program ends ===" << std::endl;
	return 0;
}
