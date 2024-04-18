#include "ScalarConverter.hpp"

bool isPseudoLiterals(const std::string &literal)
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
	else
		return false;
	return true;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &literal) //"42"ㅇㅐ느ㄴ 뭔가?  string -> int i; i: 42 ;   int 42 -> static_cast<char>(i); <float>(i);
{
	
	std::cout << "LITERAL: " << literal << std::endl;
	// detect the type of the param
	
	if (isPseudoLiterals(literal))
		return ;
	
	//std::string number;

	//if (literal[0] == '+')
	//{
	//	number = literal.substr(1, literal.length());
	//	std::cout << "REMOVE: " << number << std::endl;
	//}
	//if (literal[literal.length() - 1] == 'f')
	//{
	//	number = number.substr(0, number.length() - 1);
	//	std::cout << "REMOVE F: " << number << std::endl;
	//}

	//std::string removed(number);
	//int sign = 0;
	//int point = 0;
	//if (number[0] == '-')
	//{
	//	sign++;
	//	removed = number.substr(1, number.length() - 1);
	//	std::cout << "REMOVE NSIGN: " << removed << std::endl; 
	//}
	//for (int i = 0; i < removed.length(); i++)
	//{
	//	if (removed[i] == '.')
	//		point++;
	//	if (std::isdigit(removed[i]) == false || point > 1)
	//		{
	//			std::cout 
	//		}
		
	//}







	// convert it explicitly from string to actual type(char, int, float, double)
	// display results
	
	// conversion make no sense OR overflow -> display type conversion is impossible
	// handle numeric limits and special values


//char
// 길이가 1 && printable && !digit -> 0 ~ 9 제외한 문자들
	if (literal.length() == 1 && !isdigit(literal[0]))
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


//int
	//else if (!literal.find('.'))
	//{
	//	int i;
	//	if (!(ss >> i).fail())
	//	{
	//		std::cout << "char: impossible" << std::endl;
	//		std::cout << "int: impossible" << std::endl;

	//	}
	//}

	else
	{
		std::stringstream ss(literal);
		int i;
		float f;
		double d;

		std::cout << "char: impossible" << std::endl;
		if (!(ss >> i).fail())
		{
			//std::cout << "char: impossible" << std::endl;
			std::cout << "int: " << i << std::endl;
			//std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
			//std::cout << "double: " << static_cast<double>(i) << std::endl;
		}
		else
		{
			//std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			//std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
			//std::cout << "double: " << static_cast<double>(i) << std::endl;
		}
		ss.clear();
		ss.str(literal);

		if (!(ss >> f).fail())
		{
			//std::cout << "char: impossible" << std::endl;
			//std::cout << "int: " << static_cast<int>(f) << std::endl;
			std::cout << "float: " << f << "f" << std::endl;
			//std::cout << "double: " << static_cast<double>(f) << std::endl;
		}
		else
		{
			//std::cout << "char: impossible" << std::endl;
			//std::cout << "int: " << static_cast<int>(f) << std::endl;
			std::cout << "float: impossible" << std::endl;
			//std::cout << "double: " << static_cast<double>(f) << std::endl;
		}
		ss.clear();
		ss.str(literal);

		if (!(ss >> d).fail())
		{
			//std::cout << "char: impossible" << std::endl;
			//std::cout << "int: " << static_cast<int>(d) << std::endl;
			//std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
		else
		{
			//std::cout << "char: impossible" << std::endl;
			//std::cout << "int: " << static_cast<int>(f) << std::endl;
			//std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}

	}

	//int intMin = std::numeric_limits<int>::min();
	//int intMax = std::numeric_limits<int>::max();
	//long longMin = std::numeric_limits<long>::min();
	//long longMax = std::numeric_limits<long>::max();
	//float floatMin = std::numeric_limits<float>::min();
	//float floatMax = std::numeric_limits<float>::max();
	//double doubleMin = std::numeric_limits<double>::min();
	//double doubleMax = std::numeric_limits<double>::max();

	//std::cout << "LONG MIN: " << longMin << std::endl;
	//std::cout << "LONG MAX: " << longMax << std::endl;
	//std::cout << "FLOAT MIN: " << floatMin << std::endl;
	//std::cout << "FLOAT MAX: " << floatMax << std::endl;
	//std::cout << "DOUBLE MIN: " << doubleMin << std::endl;
	//std::cout << "DOUBLE MAX: " << doubleMax << std::endl;

	//std::cout << static_cast<float>(longMin) << std::endl;
	//std::cout << static_cast<float>(longMax) << std::endl;
	//std::cout << static_cast<double>(longMin) << std::endl;
	//std::cout << static_cast<double>(longMax) << std::endl;

	//std::cout << "CAST TO INT" << std::endl;

	//float over = 2147483648;
	//double under = -2147483649;

	//std::cout << "OVER: " << over << std::endl;
	//std::cout << "OVER to int: " << static_cast<int>(over) << std::endl;
	//std::cout << "INTMAX: " << intMax << std::endl;
	//std::cout << "UNDER: " << under << std::endl;
	//std::cout << "UNDER to int: " << static_cast<int>(under) << std::endl;
	//std::cout << "INTMIN: " << intMin << std::endl;

	//if (over > intMax)
	//	std::cout << "overflow" << std::endl;
	//if (under < intMin)
	//	std::cout << "underflow" << std::endl;

	//std::cout << static_cast<int>(floatMin) << std::endl;
	//std::cout << static_cast<int>(floatMax) << std::endl;
	//std::cout << static_cast<int>(doubleMin) << std::endl;
	//std::cout << static_cast<int>(doubleMax) << std::endl;




}
