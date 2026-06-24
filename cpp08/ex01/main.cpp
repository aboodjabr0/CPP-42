#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

static void printSeparator(const std::string& label)
{
	std::cout << "\n--- " << label << " ---" << std::endl;
}

int main()
{
	// Subject example
	printSeparator("Subject example");
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // 2
		std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl; // 14
	}

	// addNumber to full span
	printSeparator("Add to full span: expect exception");
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		try
		{
			sp.addNumber(4);
			std::cout << "No exception (unexpected)" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	// shortestSpan with fewer than 2 numbers
	printSeparator("shortestSpan with 0 numbers: expect exception");
	{
		Span sp(5);
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	printSeparator("shortestSpan with 1 number: expect exception");
	{
		Span sp(5);
		sp.addNumber(42);
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	// longestSpan with fewer than 2 numbers
	printSeparator("longestSpan with 1 number: expect exception");
	{
		Span sp(5);
		sp.addNumber(42);
		try
		{
			sp.longestSpan();
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	// addNumbers with iterator range
	printSeparator("addNumbers from iterator range");
	{
		std::vector<int> v;
		v.push_back(5);
		v.push_back(3);
		v.push_back(12);
		v.push_back(8);
		v.push_back(1);

		Span sp(10);
		sp.addNumbers(v.begin(), v.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // 2 (3-1 or 5-3)
		std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl; // 11 (12-1)
	}

	// Large test: 10,000 numbers
	printSeparator("Large test: 10,000 random numbers");
	{
		std::srand(42);
		const unsigned int SIZE = 10000;
		Span sp(SIZE);

		std::vector<int> randVec;
		for (unsigned int i = 0; i < SIZE; ++i)
			randVec.push_back(std::rand());

		sp.addNumbers(randVec.begin(), randVec.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl;
	}

	// Identical elements (shortestSpan should be 0)
	printSeparator("Identical elements: shortestSpan = 0");
	{
		Span sp(4);
		sp.addNumber(7);
		sp.addNumber(7);
		sp.addNumber(7);
		sp.addNumber(7);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // 0
		std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl; // 0
	}

	// Copy semantics
	printSeparator("Copy constructor");
	{
		Span sp1(5);
		sp1.addNumber(10);
		sp1.addNumber(20);
		sp1.addNumber(30);

		Span sp2(sp1);
		std::cout << "sp2 longestSpan: " << sp2.longestSpan() << std::endl; // 20

		sp2.addNumber(100);
		std::cout << "sp2 longestSpan after add: " << sp2.longestSpan() << std::endl; // 90
		std::cout << "sp1 longestSpan unchanged:  " << sp1.longestSpan() << std::endl; // 20
	}

	std::cout << std::endl;
	return 0;
}
