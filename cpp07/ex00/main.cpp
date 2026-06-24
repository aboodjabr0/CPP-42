#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	// equal values: should return the second one
	int x = 5;
	int y = 5;
	std::cout << "min( 5, 5 ) = " << ::min(x, y) << std::endl;
	std::cout << "max( 5, 5 ) = " << ::max(x, y) << std::endl;

	// floats
	float f1 = 3.14f;
	float f2 = 2.71f;
	::swap(f1, f2);
	std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min( f1, f2 ) = " << ::min(f1, f2) << std::endl;
	std::cout << "max( f1, f2 ) = " << ::max(f1, f2) << std::endl;

	return 0;
}
