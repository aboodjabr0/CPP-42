#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
	// --- default construction (empty array) ---
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	// --- construction with n elements (default-initialised) ---
	Array<int> ints(5);
	std::cout << "int array size: " << ints.size() << std::endl;
	for (unsigned int i = 0; i < ints.size(); i++)
		ints[i] = static_cast<int>(i * 10);
	std::cout << "ints: ";
	for (unsigned int i = 0; i < ints.size(); i++)
		std::cout << ints[i] << " ";
	std::cout << std::endl;

	// --- copy construction: deep copy ---
	Array<int> copy(ints);
	copy[0] = 999;
	std::cout << "After modifying copy[0] to 999:" << std::endl;
	std::cout << "  ints[0]  = " << ints[0]  << " (unchanged)" << std::endl;
	std::cout << "  copy[0]  = " << copy[0]  << std::endl;

	// --- assignment operator: deep copy ---
	Array<int> assigned;
	assigned = ints;
	assigned[1] = 888;
	std::cout << "After modifying assigned[1] to 888:" << std::endl;
	std::cout << "  ints[1]     = " << ints[1]     << " (unchanged)" << std::endl;
	std::cout << "  assigned[1] = " << assigned[1] << std::endl;

	// --- self-assignment safety ---
	ints = ints;
	std::cout << "Self-assignment OK, ints[0] = " << ints[0] << std::endl;

	// --- string array ---
	Array<std::string> strs(3);
	strs[0] = "hello";
	strs[1] = "world";
	strs[2] = "!";
	std::cout << "strs: ";
	for (unsigned int i = 0; i < strs.size(); i++)
		std::cout << strs[i] << " ";
	std::cout << std::endl;

	// --- const access ---
	const Array<int> cInts(ints);
	std::cout << "const access cInts[2] = " << cInts[2] << std::endl;

	// --- out-of-bounds on non-const ---
	try
	{
		ints[100] = 42;
	}
	catch (std::exception const &e)
	{
		std::cout << "Exception (non-const OOB): " << e.what() << std::endl;
	}

	// --- out-of-bounds on const ---
	try
	{
		int val = cInts[100];
		(void)val;
	}
	catch (std::exception const &e)
	{
		std::cout << "Exception (const OOB): " << e.what() << std::endl;
	}

	// --- out-of-bounds on empty array ---
	try
	{
		empty[0] = 1;
	}
	catch (std::exception const &e)
	{
		std::cout << "Exception (empty OOB): " << e.what() << std::endl;
	}

	return 0;
}
