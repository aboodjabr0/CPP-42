#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <cerrno>
#include <cstdlib>
#include <string>

static bool isCharLiteral(const std::string& s)
{
	return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

static bool isPseudoLiteralFloat(const std::string& s)
{
	return s == "-inff" || s == "+inff" || s == "nanf";
}

static bool isPseudoLiteralDouble(const std::string& s)
{
	return s == "-inf" || s == "+inf" || s == "nan";
}

static bool isIntLiteral(const std::string& s)
{
	if (s.empty())
		return false;
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		++i;
	if (i == s.size())
		return false;
	for (; i < s.size(); ++i)
		if (!std::isdigit(s[i]))
			return false;
	return true;
}

static bool isFloatLiteral(const std::string& s)
{
	if (s.empty() || s[s.size() - 1] != 'f')
		return false;
	std::string body = s.substr(0, s.size() - 1);
	if (body.empty())
		return false;
	size_t i = 0;
	if (body[i] == '+' || body[i] == '-')
		++i;
	bool hasDot = false;
	bool hasDigit = false;
	for (; i < body.size(); ++i)
	{
		if (body[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (std::isdigit(body[i]))
			hasDigit = true;
		else
			return false;
	}
	return hasDot && hasDigit;
}

static bool isDoubleLiteral(const std::string& s)
{
	if (s.empty())
		return false;
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		++i;
	bool hasDot = false;
	bool hasDigit = false;
	for (; i < s.size(); ++i)
	{
		if (s[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (std::isdigit(s[i]))
			hasDigit = true;
		else
			return false;
	}
	return hasDot && hasDigit;
}

static void printChar(double d)
{
	if (std::isnan(d) || std::isinf(d))
		std::cout << "char: impossible\n";
	else if (d < 0 || d > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'\n";
}

static void printInt(double d)
{
	if (std::isnan(d) || std::isinf(d))
		std::cout << "int: impossible\n";
	else if (d > static_cast<double>(std::numeric_limits<int>::max()) ||
			 d < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";
}

static void printFloat(double d)
{
	float f = static_cast<float>(d);
	if (std::isnan(f))
		std::cout << "float: nanf\n";
	else if (std::isinf(f))
		std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << "\n";
	else
	{
		std::ostringstream oss;
		oss << f;
		std::string s = oss.str();
		if (s.find('.') == std::string::npos && s.find('e') == std::string::npos && s.find('E') == std::string::npos)
			s += ".0";
		std::cout << "float: " << s << "f\n";
	}
}

static void printDouble(double d)
{
	if (std::isnan(d))
		std::cout << "double: nan\n";
	else if (std::isinf(d))
		std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << "\n";
	else
	{
		std::ostringstream oss;
		oss << d;
		std::string s = oss.str();
		if (s.find('.') == std::string::npos && s.find('e') == std::string::npos && s.find('E') == std::string::npos)
			s += ".0";
		std::cout << "double: " << s << "\n";
	}
}

void ScalarConverter::convert(const std::string& literal)
{
	double d = 0.0;

	if (isCharLiteral(literal))
	{
		d = static_cast<double>(literal[1]);
	}
	else if (isPseudoLiteralFloat(literal))
	{
		if (literal == "nanf")
			d = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inff")
			d = std::numeric_limits<double>::infinity();
		else
			d = -std::numeric_limits<double>::infinity();
	}
	else if (isPseudoLiteralDouble(literal))
	{
		if (literal == "nan")
			d = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf")
			d = std::numeric_limits<double>::infinity();
		else
			d = -std::numeric_limits<double>::infinity();
	}
	else if (isIntLiteral(literal))
	{
		char* end;
		errno = 0;
		long long ll = std::strtoll(literal.c_str(), &end, 10);
		if (errno != 0 || *end != '\0')
		{
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
			return;
		}
		d = static_cast<double>(ll);
	}
	else if (isFloatLiteral(literal))
	{
		char* end;
		errno = 0;
		d = static_cast<double>(std::strtof(literal.c_str(), &end));
		if (errno != 0)
		{
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
			return;
		}
	}
	else if (isDoubleLiteral(literal))
	{
		char* end;
		errno = 0;
		d = std::strtod(literal.c_str(), &end);
		if (errno != 0)
		{
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
			return;
		}
	}
	else
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		return;
	}

	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
