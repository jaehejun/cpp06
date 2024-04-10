#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << "Bad argument number" << std::endl;
	
	ScalarConverter::convert(argv[1]);
	return 0;
}