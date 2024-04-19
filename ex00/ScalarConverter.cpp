#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &literal) //"42"ㅇㅐ느ㄴ 뭔가?  string -> int i; i: 42 ;   int 42 -> static_cast<char>(i); <float>(i);
{
// pseudo literals
	if (literal == "nan")
	{
		std::cout << "char: imposible" << std::endl;
		std::cout << "int: imposible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
	{
		std::cout << "char: imposible" << std::endl;
		std::cout << "int: imposible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: imposible" << std::endl;
		std::cout << "int: imposible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	// detect the type of the param
	
	// convert it explicitly from string to actual type(char, int, float, double)
	// display results
	
	// conversion make no sense OR overflow -> display type conversion is impossible
	// handle numeric limits and special values


//char
// 길이가 1 && printable && !digit -> 0 ~ 9 제외한 문자들
	else if (literal.length() == 1 && !isdigit(literal[0]))
	{
		char value = literal[0];
		if (isprint(literal[0]))
			std::cout << "char: '" << value << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
// 길이가 3 && ' ' 로 둘러쌓여있음 && printable -> 문자들 + '0' ~ '9'
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		char value = literal[1];
		if (isprint(literal[1]))
			std::cout << "char: '" << value << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}

// char 제외한 int, float, double
	else
	{
		std::istringstream ss(literal);
		int i;
		float f;
		double d;
//소수점 없으면 -> int
		if (literal.find('.') == std::string::npos && !(ss >> i).fail())
		{
			if (isprint(i))
				std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
			else if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;

			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(i) << std::endl;
		}
//소수점 + f -> float

		else if (literal.find('.') != std::string::npos && literal.find('f') != std::string::npos && !(ss >> f).fail())
		{
			if (isprint(f))
				std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
			else if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;

			if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
				std::cout << "int: " << static_cast<int>(f) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
			
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(f) << std::endl;
		}

//소수점 !f -> double
		else if (literal.find('.') != std::string::npos && literal.find('f') == std::string::npos && !(ss >> d).fail())
		{
			if (isprint(d))
				std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
			else if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;

			if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
				std::cout << "int: " << static_cast<int>(d) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;

			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}

		else
		{
			std::cout << "char : impossible" << std::endl;
			std::cout << "int : impossible" << std::endl;
			std::cout << "float : impossible" << std::endl;
			std::cout << "double : impossible" << std::endl;
		}
	}

}

		//ss.clear();
		//ss.str(literal);