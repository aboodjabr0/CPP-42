#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

static void printSeparator(const std::string& label)
{
	std::cout << "\n--- " << label << " ---" << std::endl;
}

int main()
{
	// Subject example
	printSeparator("Subject example with MutantStack");
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl; // 17

		mstack.pop();

		std::cout << mstack.size() << std::endl; // 1

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it  = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
		std::cout << "Copied to std::stack, size: " << s.size() << std::endl;
	}

	// Same test with std::list for output comparison
	printSeparator("Same sequence with std::list");
	{
		std::list<int> lst;

		lst.push_back(5);
		lst.push_back(17);

		std::cout << lst.back() << std::endl; // 17

		lst.pop_back();

		std::cout << lst.size() << std::endl; // 1

		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		std::list<int>::iterator it  = lst.begin();
		std::list<int>::iterator ite = lst.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	// Reverse iteration
	printSeparator("Reverse iteration");
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);

		MutantStack<int>::reverse_iterator rit  = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();

		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}

	// Const iteration
	printSeparator("Const iteration");
	{
		MutantStack<int> tmp;
		tmp.push(10);
		tmp.push(20);
		tmp.push(30);

		const MutantStack<int> cmstack(tmp);

		MutantStack<int>::const_iterator cit  = cmstack.begin();
		MutantStack<int>::const_iterator cite = cmstack.end();

		while (cit != cite)
		{
			std::cout << *cit << std::endl;
			++cit;
		}
	}

	// MutantStack with std::string
	printSeparator("MutantStack<std::string>");
	{
		MutantStack<std::string> mstack;
		mstack.push("hello");
		mstack.push("world");
		mstack.push("!");

		MutantStack<std::string>::iterator it  = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "top after pop: " << mstack.top() << std::endl;
	}

	// Empty stack edge case
	printSeparator("Empty MutantStack: begin == end");
	{
		MutantStack<int> mstack;
		if (mstack.begin() == mstack.end())
			std::cout << "begin == end on empty stack (correct)" << std::endl;
	}

	// Copy assignment
	printSeparator("Copy assignment");
	{
		MutantStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);

		MutantStack<int> b;
		b = a;

		std::cout << "b.top(): " << b.top() << std::endl; // 3
		std::cout << "b.size(): " << b.size() << std::endl; // 3

		// Modifying b should not affect a
		b.pop();
		std::cout << "a.size() after b.pop(): " << a.size() << std::endl; // still 3
	}

	std::cout << std::endl;
	return 0;
}
