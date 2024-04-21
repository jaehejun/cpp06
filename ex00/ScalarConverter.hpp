#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits> // numeric_limits<type>
#include <cctype> // isprint
#include <sstream> // istringstream
#include <iomanip> // std::fixed, std::setprecision

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
	public:
		~ScalarConverter();
		static void convert(const std::string &literal);
};

#endif