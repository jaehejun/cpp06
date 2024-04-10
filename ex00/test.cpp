#include <cmath>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter
{
  public:
    // 사용자가 인스턴스를 생성할 수 없도록 생성자를 private으로 설정
    ScalarConverter() = delete;

    static void convert(const std::string &literal)
    {
        // 타입을 판별하고 해당 타입으로 변환 후 출력
        if (literal.length() == 3 && literal.front() == '\'' && literal.back() == '\'')
        {
            // char 리터럴 처리
            char c = literal[1];
            std::cout << "char: " << c << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << std::endl;
            std::cout << "double: " << static_cast<double>(c) << std::endl;
        }
        else if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos)
        {
            // int 리터럴 처리
            try
            {
                int value = std::stoi(literal);
                std::cout << "char: ";
                if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
                    std::cout << static_cast<char>(value) << std::endl;
                else
                    std::cout << "Conversion is impossible" << std::endl;
                std::cout << "int: " << value << std::endl;
                std::cout << "float: " << static_cast<float>(value) << std::endl;
                std::cout << "double: " << static_cast<double>(value) << std::endl;
            }
            catch (...)
            {
                std::cout << "Conversion error" << std::endl;
            }
        }
        else if (literal.back() == 'f')
        {
            // float 리터럴 처리
            try
            {
                float value = std::stof(literal);
                std::cout << "char: Conversion is impossible" << std::endl;
                std::cout << "int: " << static_cast<int>(value) << std::endl;
                std::cout << "float: " << value << std::endl;
                std::cout << "double: " << static_cast<double>(value) << std::endl;
            }
            catch (...)
            {
                std::cout << "Conversion error" << std::endl;
            }
        }
        else
        {
            // double 리터럴 처리
            try
            {
                double value = std::stod(literal);
                std::cout << "char: Conversion is impossible" << std::endl;
                std::cout << "int: " << static_cast<int>(value) << std::endl;
                std::cout << "float: " << static_cast<float>(value) << std::endl;
                std::cout << "double: " << value << std::endl;
            }
            catch (...)
            {
                std::cout << "Conversion error" << std::endl;
            }
        }
    }
};

int main()
{
    // 테스트 케이스
    ScalarConverter::convert("'a'");
    ScalarConverter::convert("42");
    ScalarConverter::convert("4.2");
    ScalarConverter::convert("4.2f");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("nan");

    return 0;
}
