/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:01:39 by asauafth          #+#    #+#             */
/*   Updated: 2026/03/04 18:01:41 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName)
{
	_Name = zombieName;
}

Zombie::~Zombie(void)
{
	std::cout << _Name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
