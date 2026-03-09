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

#include "Harl.hpp"

int main(void)
{
	Harl harl;
	
	std::cout << "========================================" << std::endl;
	std::cout << "Testing Harl's complaints:" << std::endl;
	std::cout << "========================================\n" << std::endl;
	
	std::cout << "1. DEBUG level complaint:" << std::endl;
	harl.complain("DEBUG");
	
	std::cout << "\n2. INFO level complaint:" << std::endl;
	harl.complain("INFO");
	
	std::cout << "\n3. WARNING level complaint:" << std::endl;
	harl.complain("WARNING");
	
	std::cout << "\n4. ERROR level complaint:" << std::endl;
	harl.complain("ERROR");
	
	std::cout << "\n5. Invalid level complaint:" << std::endl;
	harl.complain("RANDOM");
	
	std::cout << "\n6. Another invalid complaint:" << std::endl;
	harl.complain("debug");
	
	return 0;
}
