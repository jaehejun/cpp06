#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &literal) //"42"ㅇㅐ느ㄴ 뭔가?  string -> int i; i: 42 ;   int 42 -> static_cast<char>(i); <float>(i);
{
	std::cout << "LITERAL: " << literal << std::endl;
	// detect the type of the param


	// convert it explicitly from string to actual type(char, int, float, double)
	// display results
	
	// conversion make no sense OR overflow -> display type conversion is impossible
	// handle numeric limits and special values

//char 

	if (literal.length() == 1 && isprint(literal[0]) && !isnumber(literal[0]))
	{
		char value = literal[0];
		std::cout << "char: '" << value << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}

	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && isprint(literal[1]))
	{
		char value = literal[1];
		std::cout << "char: '" << value << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}

	//else if (literal)

}

//int
	//if else ()


//char
//	char c = param[0];
//	std::cout << "char: '" << c << "'" << std::endl;
//	try
//	{
//		char C = static_cast<char>(0); // Non displayable
//		std::cout << "CHAR: '" << C << "'" << std::endl;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
	
	
////int
//	try
//	{
//		int i = std::stoi(param);
//		std::cout << "int: " << i << std::endl;
//	}
//	catch(const std::exception &e)
//	{
//		//std::cout << e.what() << std::endl; // no conversion -> impossible
//		std::cout << "int: impossible" << std::endl;
//	}

////float
//	try
//	{
//		float f = std::stof(param);
//		std::cout << "float: " << f << "f" << std::endl;
//	}
//	catch(const std::exception &e)
//	{
//		std::cout << e.what() << std::endl;
//	}

////double
//	try
//	{
//		double d = std::stod(param);
//		std::cout << "double: " << d << std::endl;
//	}
//	catch(const std::exception &e)
//	{
//		std::cout << e.what() << std::endl;
//	}


//}

//static_cast<>