#include <iostream>
#include <limits>

// int 타입을 처리하는 함수
void processAndPrint(int value) {
    std::cout << "Integer value: " << value << std::endl;
}

// float 타입을 처리하는 함수
void processAndPrint(float value) {
    // float의 최대 정수 범위 내에 있는지 확인
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
        std::cout << "Value is out of int range." << std::endl;
    } else {
        // 안전하게 int로 변환
        int converted = static_cast<int>(value);
        std::cout << "Converted float to int: " << converted << std::endl;
    }
}

int main() {
    // float 예제
    float floatValue = 2147483647.0f;
    processAndPrint(floatValue);

    // int 예제
    int intValue = 2147483647;
    processAndPrint(intValue);

    return 0;
}
