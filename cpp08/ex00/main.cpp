#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void printSeparator(const std::string& label)
{
	std::cout << "\n--- " << label << " ---" << std::endl;
}

int main()
{
	// Test 1: std::vector - found
	printSeparator("vector: find existing value");
	{
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(42);
		v.push_back(7);
		v.push_back(-5);
		try
		{
			std::vector<int>::iterator it = easyfind(v, 42);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	// Test 2: std::vector - not found
	printSeparator("vector: find missing value");
	{
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		try
		{
			easyfind(v, 99);
			std::cout << "Found (unexpected)" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	// Test 3: std::list
	printSeparator("list: find first occurrence");
	{
		std::list<int> l;
		l.push_back(10);
		l.push_back(20);
		l.push_back(10); // duplicate
		l.push_back(30);
		try
		{
			std::list<int>::iterator it = easyfind(l, 10);
			std::cout << "Found first occurrence: " << *it << std::endl;
			// advance to verify it's the first one
			std::list<int>::iterator next = it;
			++next;
			std::cout << "Next element after found: " << *next << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	// Test 4: std::deque
	printSeparator("deque: find negative value");
	{
		std::deque<int> d;
		d.push_back(-100);
		d.push_back(0);
		d.push_back(100);
		try
		{
			std::deque<int>::iterator it = easyfind(d, -100);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	// Test 5: empty container
	printSeparator("empty container: expect exception");
	{
		std::vector<int> v;
		try
		{
			easyfind(v, 0);
			std::cout << "Found (unexpected)" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	// Test 6: single-element container, hit
	printSeparator("single element: find it");
	{
		std::vector<int> v;
		v.push_back(42);
		try
		{
			std::vector<int>::iterator it = easyfind(v, 42);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	// Test 7: const container
	printSeparator("const vector: find value");
	{
		std::vector<int> tmp;
		tmp.push_back(5);
		tmp.push_back(15);
		tmp.push_back(25);
		const std::vector<int> v(tmp);
		try
		{
			std::vector<int>::const_iterator it = easyfind(v, 15);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	return 0;
}
