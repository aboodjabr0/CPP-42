#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
	x++;
}

int main(void)
{
	// int array — non-const, mutating
	int arr[] = {1, 2, 3, 4, 5};
	std::size_t len = 5;

	std::cout << "Before increment:" << std::endl;
	::iter(arr, len, print<int>);

	::iter(arr, len, increment<int>);
	std::cout << "After increment:" << std::endl;
	::iter(arr, len, print<int>);

	// const string array — function takes const ref
	std::string words[] = {"hello", "world", "cpp", "templates"};
	std::cout << "\nStrings:" << std::endl;
	::iter(words, 4, print<std::string>);

	// const array
	const double dbl[] = {1.1, 2.2, 3.3};
	std::cout << "\nConst doubles:" << std::endl;
	::iter(dbl, 3, print<double>);

	return 0;
}
