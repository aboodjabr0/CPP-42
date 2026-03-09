/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:01:33 by asauafth          #+#    #+#             */
/*   Updated: 2026/03/04 18:01:35 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string _Name;

public:
	Zombie(std::string zombieName);
	~Zombie(void);
	
	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
