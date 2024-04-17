#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Bad argument number" << std::endl;
		return 1;
	}
	
	ScalarConverter::convert(argv[1]);

	return 0;
}

// char, int, float, double의 범위도 고려해야함?