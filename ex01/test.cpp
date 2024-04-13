#include <iostream>
#include <cstdint>

int main() {
    // 동적으로 int 타입의 메모리를 할당하여 포인터를 얻습니다.
    int* originalPtr = new int(10);

    // originalPtr의 메모리 주소를 출력합니다 (64비트).
    std::cout << "Original pointer (64-bit): " << originalPtr << std::endl;

    // originalPtr의 메모리 주소를 uintptr_t로 변환하여 모든 비트를 보존합니다.
    uintptr_t fullAddress = reinterpret_cast<uintptr_t>(originalPtr);
    std::cout << "Full address (uintptr_t): " << fullAddress << std::endl;

    // fullAddress를 unsigned int로 변환하여 주소 정보의 일부를 손실시킵니다.
    unsigned int lostAddress = static_cast<unsigned int>(fullAddress);
    std::cout << "Address in unsigned int (possible loss): " << lostAddress << std::endl;

    // lostAddress를 다시 uintptr_t로 변환합니다.
    uintptr_t recoveredAddress = static_cast<uintptr_t>(lostAddress);

    // recoveredAddress를 포인터로 변환합니다.
    int* recoveredPtr = reinterpret_cast<int*>(recoveredAddress);
    std::cout << "Recovered pointer (64-bit): " << recoveredPtr << std::endl;

    // 메모리 해제
    delete originalPtr;

    return 0;
}
