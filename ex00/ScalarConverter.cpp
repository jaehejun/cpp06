#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &literal)
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

//char
// 길이가 1 && !digit -> 0 ~ 9 제외한 문자들
	else if (literal.length() == 1 && !isdigit(literal[0]))
	{
		char c = literal[0];
		if (isprint(literal[0]))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
	}
// 길이가 3 && ' ' 로 둘러쌓여있음 -> '0' ~ '9'
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		char c = literal[1];
		if (isprint(literal[1]))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
	}

// char 제외한 int, float, double
	else
	{
		std::istringstream ss(literal);
		//char c;
		int i;
		float f;
		double d;

//소수점, f 없으면 -> int
		if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos && (!(ss >> i).fail()))
		{
			if (isprint(i))
				std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
			else if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
			return ;
		}

//소수점 + f -> float
		else if (literal.find('.') != std::string::npos && literal.find('f') != std::string::npos)
		{
			ss.str(literal.substr(0, literal.length() - 1));
			ss >> d;

			ss.clear();
			ss.str(literal.substr(0, literal.length() - 1));
			if (!(ss >> f).fail())
			{
				if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
				{
					if (isprint(static_cast<char>(f)))
						std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
					else
						std::cout << "char: Non displayable" << std::endl;
				}
				else
					std::cout << "char: impossible" << std::endl;

				if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
				{
					if ((f > 0 && static_cast<int>(f) > 0) || (f < 0 && static_cast<int>(f) < 0))
						std::cout << "int: " << static_cast<int>(f) << std::endl;
					else
						std::cout << "int: impossible" << std::endl;
				}
				else
					std::cout << "int: impossible" << std::endl;
				
				std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
				std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
				return ;
			}
		}

//소수점, !f -> double
		else if (literal.find('.') != std::string::npos && literal.find('f') == std::string::npos && (!(ss >> d).fail()))
		{
			if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
			{
				if (isprint(static_cast<char>(d)))
					std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
			}
			else
				std::cout << "char: impossible" << std::endl;

			if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
				std::cout << "int: " << static_cast<int>(d) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
			
			if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max())
				std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
			else
				std::cout << "float: impossible" << std::endl;

			std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
			return ;
		}

		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
	}
}