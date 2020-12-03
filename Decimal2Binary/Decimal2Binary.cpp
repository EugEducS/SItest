#include <iostream>
#include <math.h>
#include <limits>

void DecimalToBinary(int number) {
    const char* sign = number < 0 ? "-" : "";
    int binarySize = 0;
    char binary[32] = "";
    int absNumber = abs(number);
    while (absNumber > 0) {
        binary[binarySize] = absNumber % 2 == 0 ? '0' : '1';
        binarySize++;
        absNumber /= 2;
    }
    if (binarySize > 0) {
        std::cout << sign;
        for (int i = binarySize - 1; i >= 0; i--) {
            std::cout << binary[i];
        }
    }
}

int main()
{
    int number;
    try {
        while (std::cin.good()) {
            std::cout << "Enter a number between\n"
                << std::numeric_limits<int>::min() << " and " << std::numeric_limits<int>::max() 
                << "\n to convert it to binary or any char or another number to exit\n";
            std::cin >> number;
            std::cout << "\nBinary value is:\n";
            DecimalToBinary(number);
            std::cout << "\n\n";
        }
    } catch (...) {
        std::cout << "Decimal to binary convertion error\n";
    }
    std::cout << "Program will be closed\n";
    
    return 0;
}
