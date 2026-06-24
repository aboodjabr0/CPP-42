#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool isLeapYear(int y) {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7) continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}
	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(year))
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::parseValue(const std::string& valStr, double& out) const {
	if (valStr.empty())
		return false;
	char* end;
	double val = std::strtod(valStr.c_str(), &end);
	if (end == valStr.c_str() || *end != '\0')
		return false;
	out = val;
	return true;
}

double BitcoinExchange::getRate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = _db.lower_bound(date);
	if (it == _db.end() || it->first != date) {
		if (it == _db.begin())
			return -1.0;
		--it;
	}
	return it->second;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open database file.");

	std::string line;
	std::getline(file, line); // skip header "date,exchange_rate"

	while (std::getline(file, line)) {
		if (line.empty()) continue;
		std::size_t comma = line.find(',');
		if (comma == std::string::npos) continue;
		std::string date = line.substr(0, comma);
		std::string rateStr = line.substr(comma + 1);
		double rate;
		if (!parseValue(rateStr, rate)) continue;
		_db[date] = rate;
	}
}

void BitcoinExchange::processInput(const std::string& filename) const {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;
	while (std::getline(file, line)) {
		if (line.empty()) continue;
		// Skip the header line
		if (firstLine && line.find("date") != std::string::npos && line.find("value") != std::string::npos) {
			firstLine = false;
			continue;
		}
		firstLine = false;

		std::size_t sep = line.find(" | ");
		if (sep == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sep);
		std::string valStr = line.substr(sep + 3);

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double val;
		if (!parseValue(valStr, val)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (val < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (val > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		double rate = getRate(date);
		if (rate < 0) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		std::cout << date << " => " << val << " = " << val * rate << std::endl;
	}
}
