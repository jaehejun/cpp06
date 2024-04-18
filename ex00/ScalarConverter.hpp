#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits> // numeric_limits<type>
#include <cctype> //isalnum, isalpha, isdigit, isprint
#include <cstdlib> // atoi
#include <sstream> //stringstream

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